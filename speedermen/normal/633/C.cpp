#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;
const int MD = 1000000007;

#define ll long long
#define pb push_back
#define mp make_pair
#define X first
#define Y second

struct node {
    int to[26];
    int id;
} f[N];

int n, m, rt;
string s, ps[N];
int d[N], p[N];

void add (string s, int id) {
    int nt = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (f[nt].to[tolower(s[i]) - 'a'] == -1)
            f[nt].to[tolower(s[i]) - 'a'] = rt++;
        nt = f[nt].to[tolower(s[i]) - 'a'];
    }
    f[nt].id = id;
}

int main()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
    ios_base::sync_with_stdio(0);
    cin >> n >> s >> m;
    memset(f, -1, sizeof f);
    memset(p, -1, sizeof p);
    rt++;
    for (int i = 0; i < m; ++i) {
        cin >> ps[i];
        add(ps[i], i);
    }
    d[n] = 1;
    for (int i = n; i >= 0; --i) {
        if (d[i] != 0)
        {
            int nt = 0;
            for (int j = i - 1; j >= max(0, i - 1000); --j) {
                if (f[nt].to[s[j] - 'a'] == -1)
                    break;
                nt = f[nt].to[s[j] - 'a'];
                if (f[nt].id != -1) {
                    d[j] = 1;
                    p[j] = f[nt].id;
                }
            }
        }
    }
    vector < int > ans;
    for (int x = 0; x != n; x += ps[p[x]].length()) {
        ans.push_back(p[x]);
    }
    for (int i = 0; i < (int)ans.size(); ++i) {
        if (i) cout << " ";
        cout << ps[ans[i]];
    }
    return 0;
}