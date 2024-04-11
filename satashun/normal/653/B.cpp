#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

int n, q;

set<string> u;
vector<string> t[7];

void dfs(string s, int p)
{
    if (p == n - 1) {
	u.insert(s);
	return ;
    }

    int i = s.back() - 'a';
    s.pop_back();

    for (string ad : t[i]) {
	s += ad;
	dfs(s, p + 1);
	s.pop_back();
	s.pop_back();
    }
}

int main() {
    cin >> n >> q;

    rep(i, q) {
	string a, b;
	cin >> a >> b;
	swap(a[0], a[1]);
	t[b[0] - 'a'].pb(a);
    }

    string s = "a";
    dfs(s, 0);

    cout << u.size() << endl;

    return 0;
}