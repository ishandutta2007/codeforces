#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;
const int LGN = 20;
const int MD = 1000000007;

#define ll long long
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define FOR(i, a, b) for (int _tmp = b, i = a; i <= _tmp; ++i)

typedef pair < int, int > pii;
typedef vector < int > vi;
typedef vector < vi > vvi;

struct T {
	int to[2];
	int len, pos, cnt;
	int link;
} t[N * 2];

char s[N];
int L[N], up[LGN][N];
int pt, last, n;
vi fi[N];

void build()
{
	t[0].cnt = 0;
	t[0].to[0] = t[0].to[1] = 0;
	t[0].link = -1;
	t[0].len = 0;
	t[0].pos = 0;
	pt = last = 0;
}

void add(char c, int pos)
{
	c = (c == '(' ? 0 : 1);
	int cur = ++pt;
	int p = last;
	t[cur].len = t[last].len + 1;
	t[cur].pos = pos;
	t[cur].cnt = 1;
	while (p >= 0 && t[p].to[c] == 0)
    {
		t[p].to[c] = cur;
		p = t[p].link;
	}
	last = cur;
	if (p < 0)
	{
		t[cur].link = 0;
		return;
	}
	int q = t[p].to[c];
	if (t[q].len == t[p].len + 1)
	{
		t[cur].link = q;
		return;
	}
	int clone = ++pt;
	t[clone].to[0] = t[q].to[0];
	t[clone].to[1] = t[q].to[1];
	t[clone].link = t[q].link;
	t[clone].len = t[p].len + 1;
	t[q].link = t[cur].link = clone;
	while (p >= 0 && t[p].to[c] == q)
    {
		t[p].to[c] = clone;
		p = t[p].link;
	}
}

int GET(int pos, int len) {
    int res = 0, opos = pos;
    for (int i = LGN - 1; i >= 0; --i) {
        if (up[i][pos] != -1 && opos - (up[i][pos] - 1) <= len) {
            pos = up[i][pos] - 1;
            res += 1 << i;
        }
    }
    return res;
}
/*
int calc(int n, string s) {
    set < string > st;
    FOR(i, 1, n) {
        string w;
        int bal = 0;
        FOR(j, i, n) {
            w += s[j];
            bal += (s[j] == '(' ? 1 : -1);
            if (bal < 0) {
                break;
            }
            if (bal == 0) {
                st.insert(w);
            }
        }
    }
    for (set < string > :: iterator it = st.begin(); it != st.end(); ++it) cout << *it << endl;
    return st.size();
}
*/
int main()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
    ios_base::sync_with_stdio(0);
    int n;
    string s;
    cin >> n >> s;
    s = "#" + s;
//    cout << calc(n, s) << endl;
    build();
    FOR(i, 1, n)
        add(s[i], i);
    memset(up, -1, sizeof(up));
    ll ans = 0;
    FOR(i, 1, n) {
		if (s[i] == '(') continue;
		int last = i - 1 - L[i - 1];
		if (last > 0 && s[last] == '(') {
			L[i] = L[last - 1] + (i - last) + 1;
			up[0][i] = last;
			FOR(k, 1, LGN - 1)
				if (up[k - 1][i] > 0)
					up[k][i] = up[k - 1][up[k - 1][i] - 1];
		}
	}
	for (int i = 1; i <= pt; ++i)
		fi[t[i].len].pb(i);
	for (int len = n; len > 0; --len) {
		for (int i = 0; i < fi[len].size(); ++i) {
			int v = fi[len][i];
			int pos = t[v].pos;
			t[t[v].link].pos = t[v].pos;
			if (s[pos] == ')') {
                ans += GET(t[v].pos, t[v].len) - GET(t[v].pos, t[t[v].link].len);
			}
		}
	}
	cout << ans << endl;
    return 0;
}