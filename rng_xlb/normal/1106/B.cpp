#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<set> 
#define LL long long
#define mp make_pair
#define FS first
#define SC second
#define pll pair<LL,LL>
#define sta pair<pair<LL,LL>,LL>
#define M 200020
using namespace std;
LL read(){
	LL nm=0,fh=1;char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
LL n,m,ans,a[M],c[M],tot;
set< sta > S;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read(),tot+=a[i];
	for(int i=1;i<=n;i++) c[i]=read(),S.insert(mp(mp(c[i],i),a[i]));
//	for(LL i=1;i<=n;i++) printf("%lld\n",a[i]);
	while(m--){
		LL ct=read(),k=read(),ans=0; swap(ct,k);
	//-	printf("------------    %lld\n",tot);
		sta tg=mp(mp(c[k],k),0);
		set< sta >::iterator it=S.lower_bound(tg);
		if(it!=S.end()&&(*it).FS.SC==k){
			tg=*it,S.erase(it);
	//		printf("--   %lld %lld %lld\n",tg.FS.FS,tg.FS.SC,tg.SC);
			LL dec=min(tg.SC,ct);
			ct-=dec,tg.SC-=dec;
			ans+=dec*tg.FS.FS;
			if(tg.SC>0) S.insert(tg);
		}
		while(ct>0){
			it=S.begin();
			if(it==S.end()) break;
			tg=*it,S.erase(it);
			LL dec=min(tg.SC,ct);
			ct-=dec,tg.SC-=dec;
			ans+=dec*tg.FS.FS;
			if(tg.SC>0) S.insert(tg);
		} printf("%lld\n",ct>0?0ll:ans);
	} return 0;
}