//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(int (x)=(y);(x)<=(z);(x)++)
#define per(x,y,z) for(int (x)=(y);(x)>=(z);(x)--)
#define fil(x,y) memset((x), (y), sizeof(x))
using namespace std;
typedef long long ll;

int T, n, ma[2];
string s;

int main() {
	scanf("%d", &T);
	while(T--) {
		ma[0] = ma[1] = 0;
		scanf("%d", &n);
		cin>>s;
		rep(i, 1, n-1) if(s[i] == s[i-1]) ++ma[s[i]^48];
		printf("%d\n", max(ma[0], ma[1]));
	}
	return 0;
}