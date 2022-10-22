#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int a=0,fh=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')fh=-1;c=getchar();}
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a*fh;
}
#define MN 55
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define vc vector<int>
int T,n,m;
char ch[MN][MN];
signed main(){
	T=read();
	while(T--){
		n=read();m=read();
		for(int i=1;i<=n;++i)scanf("%s",ch[i]+1);
		bool A=0,B=0;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j){
				if(ch[i][j]!='.'){
					if((i+j+(ch[i][j]=='R'))%2==0)A=1;
					else B=1;
				}
			}
		if(A&&B)puts("NO");
		else {
			puts("YES");
			if(A){
			for(int i=1;i<=n;++i){
				for(int j=1;j<=m;++j)
					if((i+j)%2==0)putchar('W');
					else putchar('R');
				puts("");
			}
		}
		else{	
			for(int i=1;i<=n;++i){
				for(int j=1;j<=m;++j)
					if((i+j)%2==1)putchar('W');
					else putchar('R');
				puts("");
			}
		}
		}
	}
	return 0;
}