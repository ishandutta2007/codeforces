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

int n;
string S, T;

bool ok(string s)
{
    int p1 = 0, p2 = 0;
    rep(i, s.size()) {
	if (p1 < n && s[i] == S[p1]) ++p1;
	if (p2 < n && s[i] == T[p2]) ++p2;
    }
    return p1 == n && p2 == n;
}

int main() {
    cin >> n >> S >> T;

    rep(i, n) if (S[i] != T[i]) {
	string a, b;
	a = b = S.substr(0, i);
	a += S[i];
	b += T[i];
	a += T.substr(i);
	b += S.substr(i);

	int ret = ok(a) + ok(b);
	cout << ret << endl;
	return 0;
    }
}