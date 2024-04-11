#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
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
int n,m;
int cow[5010][5010];
int f[5010],h[5010];
int s[5010];
int suml[5010],sumr[5010];
int num[5010];
int ans,cnt=1;
int tmpans,tmpcnt;
int ctri[5010],ways[5010];
const int mod=1e9+7;
int qpow(int x,int k){
	int res=1;
	while(k){
		if(k&1) res=1ll*x*res%mod;
		x=1ll*x*x%mod;
		k>>=1; 
	}
	return res;
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i) s[i]=read(),++sumr[s[i]];
	for(int i=1;i<=m;++i) {f[i]=read(),h[i]=read();if(h[i]<=sumr[f[i]]) cow[f[i]][++num[f[i]]]=h[i];}
	for(int i=1;i<=n;++i) sort(cow[i]+1,cow[i]+num[i]+1);
	for(int i=1;i<=n;++i) if(num[i]){ ++ans;cnt=(1ll*cnt*num[i])%mod;ctri[i]=1,ways[i]=num[i];}
	tmpans=ans,tmpcnt=cnt;
//	printf("%d %d\n",ans,cnt);
	for(int i=1;i<=n;++i){
		if(num[s[i]]==0) continue ;
		++suml[s[i]];--sumr[s[i]];
		tmpans-=ctri[s[i]];tmpcnt=1ll*tmpcnt*qpow(ways[s[i]],mod-2)%mod;
//		printf("i:%d,tmpans:%d tmpcnt:%d\n",i,tmpans,tmpcnt);
		int p=lower_bound(cow[s[i]]+1,cow[s[i]]+num[s[i]]+1,suml[s[i]])-cow[s[i]];
		if(cow[s[i]][p]==suml[s[i]]){
			int tans=tmpans,tcnt=tmpcnt;
			int sr=upper_bound(cow[s[i]]+1,cow[s[i]]+num[s[i]]+1,sumr[s[i]])-cow[s[i]]-1;
			if(sr>=p) --sr;
			++tans;
//			printf("suml:%d,sumr:%d,p:%d,sr:%d,tans:%d,tcnt:%d\n",suml[s[i]],sumr[s[i]],p,sr,tans,tcnt);
			if(sr>0) ++tans,tcnt=1ll*tcnt*sr%mod;
//			printf("%d %d\n",tans,tcnt);
			
			if(tans>ans) ans=tans,cnt=tcnt;
			else if(tans==ans) cnt=(cnt+tcnt)%mod;
		}
		int sl=upper_bound(cow[s[i]]+1,cow[s[i]]+num[s[i]]+1,suml[s[i]])-cow[s[i]]-1;
		int sr=upper_bound(cow[s[i]]+1,cow[s[i]]+num[s[i]]+1,sumr[s[i]])-cow[s[i]]-1;
		if(sl==sr&&sl==1){
			ctri[s[i]]=1,ways[s[i]]=2;
		}
		else if(sl==0&&sr==0) ctri[s[i]]=0,ways[s[i]]=1;
		else if(sl==0||sr==0) ctri[s[i]]=1,ways[s[i]]=(sl+sr);
		else{
			ctri[s[i]]=2;if(sl<sr) swap(sl,sr);ways[s[i]]=1ll*(sl-1)*sr%mod;
		}
		tmpans+=ctri[s[i]],tmpcnt=1ll*tmpcnt*ways[s[i]]%mod;
	}
	printf("%d %d\n",ans,cnt%mod);
}