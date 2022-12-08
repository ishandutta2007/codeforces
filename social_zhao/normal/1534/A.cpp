#include<bits/stdc++.h>
#define rep(i,a,b) for(R int i=a;i<=b;i++)
#define R register
#define endl putchar('\n')
const int N=505;
using namespace std;

int n,m;
char s[N][N],mp[N][N],a[2];

void solve() {
	a[0]='W',a[1]='R';
	rep(i,1,n) rep(j,1,m) {
		if(s[i][j]!='.') {
			a[(i+j)&1]=s[i][j];
			a[((i+j)&1)^1]=s[i][j]=='W'?'R':'W';
			break;
		}
	}
	rep(i,1,n) rep(j,1,m) {
		if(s[i][j]!='.') {
			if(s[i][j]!=a[(i+j)&1]) {
				printf("NO\n"); return;
			}
		}
	}
	printf("YES\n");
	rep(i,1,n) {
		rep(j,1,m) printf("%c",a[(i+j)&1]);
		endl;
	}
}

int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&n,&m);
		rep(i,1,n) scanf("%s",s[i]+1);
		solve();
	}
	return 0;
}