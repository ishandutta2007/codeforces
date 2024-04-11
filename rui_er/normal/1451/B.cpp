//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(int (x)=(y);(x)<=(z);(x)++)
#define per(x,y,z) for(int (x)=(y);(x)>=(z);(x)--)
#define fil(x,y) memset((x), (y), sizeof(x))
using namespace std;
typedef long long ll;

int T, n, q;
string s;

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &q); cin>>s;
		while(q--) {
			int l, r, _ = 0;
			scanf("%d%d", &l, &r); --l; --r;
			per(u, l-1, 0) if(s[u] == s[l]) {puts("YES"); _ = 1; break;}
			if(!_) rep(u, r+1, n-1) if(s[u] == s[r]) {puts("YES"); _ = 1; break;}
			if(!_) puts("NO");
		}
	}
	return 0;
}