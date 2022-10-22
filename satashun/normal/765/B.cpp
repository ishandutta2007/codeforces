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

string s;
int mx;

int main() {
	cin >> s;

	rep(i, s.size()) {
		int c = s[i]-'a'+1;
		if (mx + 1 < c) {
			puts("NO");
			return 0;
		}
		mx = max(mx, c);
	}

	puts("YES");
	return 0;
}