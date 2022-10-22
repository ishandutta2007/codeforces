#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define int long long
using namespace std;

inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
int s,ans;
int f[70][210][2];
int calc(int tar,int cnt,int l1,int l2){
	if(tar&1) return 0;
	memset(f,0,sizeof(f));
	f[0][0][0]=1;
	for(int i=1;i<=60;++i){
		int mx=(i<=l1)+(i<=l2);
		for(int j=0;j<=cnt;++j){
			if(!(tar&(1ll<<i))){
				f[i][j][0]+=f[i-1][j][0];
				if(j>=2&&mx==2)f[i][j][1]+=f[i-1][j-2][0];
				if(j>=1&&mx>=1)f[i][j][1]+=1ll*mx*f[i-1][j-1][1];
			}
			else{
				f[i][j][0]+=f[i-1][j][1];
				if(j>=1&&mx>=1) f[i][j][0]+=1ll*mx*f[i-1][j-1][0];
				if(j>=2&&mx==2) f[i][j][1]+=f[i-1][j-2][1];
			}
		}
	}
	return f[60][cnt][0];
}
signed main(){
	s=read();
	for(int i=1;(1ll<<i-1)<=s;++i){
		int t=s/((1ll<<i)-1);
		int tmp=s-(t*((1ll<<i)-1));
		if(t==0||tmp<0) continue ;
//		printf("i:%d,")
		for(int j=i-1;j>0;--j){
			if(tmp>=((1ll<<j)-1)) tmp-=((1ll<<j)-1);
		}
		if(tmp==0) ++ans;
	}
//	printf("%d\n",ans);
	for(int h1=1;(1ll<<h1)<=s;++h1){
		for(int h2=1;(1ll<<h1)+(1ll<<h2)<=s;++h2){
			int x=(s-(1ll<<h2)+1)/((1ll<<h1+1)+(1ll<<h2+1)-3);
			int tmp=x*((1ll<<h1+1)+(1ll<<h2+1)-3)+(1ll<<h2)-1;
			tmp=s-tmp;if(x==0) continue ;
//			printf("i:%d,j:%d,x:%d,tmp:%d\n",h1,h2,x,tmp);
//			printf("h1:%d,h2:%d,")
			if(tmp<0) continue ;
			if(tmp==0){
				++ans;continue ;
			}
//			printf("h1:%d,h2:%d,x:%d,tmp:%d\n",h1,h2,x,tmp);
			for(int k=0;k<h1+h2-1;++k){
				ans+=calc(tmp+k,k,h1-1,h2-1);
			}
//			printf("%d\n",ans);
//			printf("h1:%d,h2:%d,ans:%d\n",h1,h2,ans);
		}
	}
	printf("%lld\n",ans);
}