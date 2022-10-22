#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#define PII pair<int,int>
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int T;
int n;
char g[310][310];
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i){
			scanf("%s",g[i]+1);
		}
		int w1,b1,w2,b2,w3,b3;
		w1=b1=w2=b2=w3=b3=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				switch((i+j)%3){
					case 0:{
						if(g[i][j]=='X') ++b3;
						else if(g[i][j]=='O') ++w3;
						break;
					}
					case 1:{
						if(g[i][j]=='X') ++b1;
						else if(g[i][j]=='O') ++w1;
						break;
					}
					case 2:{
						if(g[i][j]=='X') ++b2;
						else if(g[i][j]=='O') ++w2;
						break;
					}
				}
			}
		}
		int ans=min(min(min(b1+w2,w1+b2),min(b1+w3,w1+b3)),min(b2+w3,w2+b3));
		if(ans==b1+w2){
			for(int i=1;i<=n;++i){
				for(int j=1;j<=n;++j){
					if(g[i][j]=='.') continue ;
					if((i+j)%3==1) g[i][j]='O';
					else if((i+j)%3==2) g[i][j]='X';
				}
			}
		}
		else if(ans==w1+b2){
			for(int i=1;i<=n;++i){
				for(int j=1;j<=n;++j){
					if(g[i][j]=='.') continue ;
					if((i+j)%3==1) g[i][j]='X';
					else if((i+j)%3==2) g[i][j]='O';
				}
			}
		}
		else if(ans==b1+w3){
			for(int i=1;i<=n;++i){
				for(int j=1;j<=n;++j){
					if(g[i][j]=='.') continue ;
					if((i+j)%3==1) g[i][j]='O';
					else if((i+j)%3==0) g[i][j]='X';
				}
			}
		}
		else if(ans==w1+b3){
			for(int i=1;i<=n;++i){
				for(int j=1;j<=n;++j){
					if(g[i][j]=='.') continue ;
					if((i+j)%3==1) g[i][j]='X';
					else if((i+j)%3==0) g[i][j]='O';
				}
			}
		}
		else if(ans==b2+w3){
			for(int i=1;i<=n;++i){
				for(int j=1;j<=n;++j){
					if(g[i][j]=='.') continue ;
					if((i+j)%3==2) g[i][j]='O';
					else if((i+j)%3==0) g[i][j]='X';
				}
			}
		}
		else if(ans==w2+b3){
			for(int i=1;i<=n;++i){
				for(int j=1;j<=n;++j){
					if(g[i][j]=='.') continue ;
					if((i+j)%3==2) g[i][j]='X';
					else if((i+j)%3==0) g[i][j]='O';
				}
			}
		}
		for(int i=1;i<=n;++i) printf("%s\n",g[i]+1);
	}
	return 0;
}