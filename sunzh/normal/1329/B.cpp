#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int T;
int d,m;
int main(){
	T=read();
	while(T--){
		d=read(),m=read();
		int ans=0;
		for(int i=0;i<=0;++i){
			int res=0;
			if((1<<i)<=d){
				res=1;int tmp=1;
				for(int j=i;j<=30;++j) if((1<<j)<=d){
					res=1ll*tmp*min(d-(1<<j)+1,(1<<j))%m;
					// printf("i:%d,j:%d,%d\n",i,j,res);
					(ans+=res)%=m;
					(tmp+=res)%=m;
				}
			}
		}
		printf("%d\n",ans);
	}
}