#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
using namespace std;
const int N=2005,inf=0x3f3f3f3f;
char p[N][N];
int t[N],n,m;
int main(){
	scanf("%d%d\n",&n,&m);
	rep(i,n){
		rep(j,m){
			scanf("%c",p[i]+j);
			if(p[i][j]=='1')++t[j];
		}
		getchar();
	}
	rep(i,n){
		bool flag=1;
		rep(j,m)if(p[i][j]=='1'&&t[j]==1){flag=0;break;}
		if(flag){puts("YES");//system("pause");
return 0;}
	}
	puts("NO");
	//system("pause");
}