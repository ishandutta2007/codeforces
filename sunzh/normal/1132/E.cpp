#include<iostream>
#include<cstdio>
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){ if(c=='-') f=-1; c=getchar();}
	while(isdigit(c)){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}
int w,tw,sum;
int ans,n;
int cnt[10];
int v[3010],f[3010];
signed main(){
	w=read();
	tw=max(0ll,w-840);
	for(int i=1;i<=8;++i){
		cnt[i]=read();
		sum+=i*cnt[i];
	} 
	if(sum<=w){
		printf("%lld\n",sum);
		return 0;
	} 
	w-=tw;
	for(int i=1;i<=8;++i){
		int t=min(cnt[i],tw/i);
        if(cnt[i]-t<10) t=max(0ll,cnt[i]-10);
        ans+=t*i;
        tw-=t*i;
        cnt[i]-=t;
	}
	w+=tw;
	for(int i=1;i<=8;++i){
		int s=1;
		while(s<=cnt[i]){
			v[++n]=s*i;
			cnt[i]-=s;
			s<<=1ll;
		}
		if(cnt[i]) v[++n]=cnt[i]*i;
	}
	for(int i=1;i<=n;++i){
		for(int j=w;j>=v[i];--j){
			f[j]=max(f[j],f[j-v[i]]+v[i]);
		}
	}
	printf("%lld\n",ans+f[w]);
	return 0;
}