#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){	if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) {x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
inline void print(int x){
	if(x<0) x=-x,putchar('-');
	if(x>=10) print(x/10);
	putchar(x%10+48);
}
int k;
int a[20][5010];
int sum[20],su;
int sz[20];
map<int,int>exi;
int fr[1<<16],pre[1<<16];
bool can[1<<16];
pair<int,int>ans[20];
signed main(){
	memset(fr,0x7f,sizeof(fr));
	k=read();
	for(int i=1;i<=k;++i){
		sz[i]=read();
		for(int j=1;j<=sz[i];++j) a[i][j]=read(),sum[i]+=a[i][j],exi[a[i][j]]=i;
		su+=sum[i];
	}
	if(su%k!=0){
		printf("NO\n");return 0;
	}
	int avg=su/k;
	for(int i=1;i<=k;++i){
		int s=0;
		if(sum[i]==avg){
			can[1<<i-1]=1;fr[1<<i-1]=a[i][1];
		}
		for(int j=1;j<=sz[i];++j){
			s=avg-sum[i]+a[i][j];
			if(exi.count(s)){
				bool fl=1;
				int S=1<<i-1;
				while(exi[s]!=i){
					if(S&(1<<exi[s]-1)){
						fl=0;break ;
					}
					S|=(1<<exi[s]-1);
					s=avg-sum[exi[s]]+s;
				}
				if(fl&&fr[S]>=0x7f7f7f7f&&s==a[i][j]) fr[S]=a[i][j],can[S]=1;
			}
		}
	}
	for(int S=1;S<(1<<k);++S){
		if(can[S]) pre[S]=S;
		else{
			for(int i=S;i;i=(i-1)&S){
				if(fr[S^i]<0x3f3f3f3f&&can[i]){
					pre[S]=S^i;
					can[S]=1;
					break ;
				}
			}
		}
	}
	if(can[(1<<k)-1]==0) {
		printf("NO\n");return 0;
	}
	printf("Yes\n");
	int S=(1<<k)-1;
	while(S){
		int S1=pre[S];
		int p=exi[fr[S1]];
		int s=avg-sum[p]+fr[S1];
		while(exi[s]!=exi[fr[S1]]){
			ans[exi[s]]=make_pair(s,p);
			p=exi[s];
			s=avg-sum[exi[s]]+s;
		}
		ans[exi[s]]=make_pair(s,p);
		S=S^pre[S];
	}
	for(int i=1;i<=k;++i) printf("%lld %lld\n",ans[i].first,ans[i].second);
	return 0;
}