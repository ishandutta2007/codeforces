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
char str[5010];
int main(){
	T=read();
	while(T--){
		scanf("%s",str+1);
		int x=0,y=0;
		int n=strlen(str+1);
		vector<PII>opt;
		int ansx=0,ansy=0;
		for(int i=1;i<=n;++i){
			switch(str[i]){
				case 'L':--x;break ;
				case 'R':++x;break ;
				case 'D':--y;break ;
				case 'U':++y;break ;
			}
			opt.ep(x,y);
		}
		for(auto p:opt){
			if(p.fi==0&&p.se==0) continue ;
			int dx=0,dy=0;
			for(int i=1;i<=n;++i){
				int tx=dx,ty=dy;
				switch(str[i]){
					case 'L':--tx;break ;
					case 'R':++tx;break ;
					case 'D':--ty;break ;
					case 'U':++ty;break ;
				}
				if(p!=mp(tx,ty)) dx=tx,dy=ty;
			}
			if(dx==0&&dy==0){
				ansx=p.fi,ansy=p.se;break ;
			}
		}
		printf("%d %d\n",ansx,ansy);
	}
}