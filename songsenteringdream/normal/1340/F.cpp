#include<cstdio>
#include<iostream>
using namespace std;
const int o=1e5+10,B=330,MOD=998244353;
int n,k,q,a[o],st[o],tp,St[o],Tp,b[o],bl[o],cnt,pre[o/B+10][B+10],suf[o/B+10][B+10],c0[o],c1[o],pos[o],pw[o];
bool ill[o],flg;
inline void build(int id){
	Tp=ill[id]=c0[id]=c1[id]=0;
	for(int i=1;i<=cnt;++i)
		if(b[i]>0) St[++Tp]=b[i];
		else if(!Tp||St[Tp]<0) St[++Tp]=b[i];
		else if(b[i]+St[Tp]){ill[id]=1;return;}
		else --Tp;
	for(int i=1;i<=Tp&&St[i]<0;++i) ++c0[id],pre[id][c0[id]]=(pre[id][c0[id]-1]*(k+1ll)-St[i])%MOD;
	for(int i=Tp;i&&St[i]>0;--i) ++c1[id],suf[id][c1[id]]=(suf[id][c1[id]-1]*(k+1ll)+St[i])%MOD;
}
inline int calc(int*hsh,int l,int r){return (hsh[r]+(MOD-pw[r-l+1])*1ll*hsh[l-1])%MOD;}
inline void push(int id){
	if(flg|=ill[id]) return;
	int p=1,len;
	for(;tp&&p<=c0[id];p+=len){
		len=min(c0[id]+1-p,c1[st[tp]]+1-pos[tp]);
		if(calc(pre[id],p,p+len-1)^calc(suf[st[tp]],pos[tp],pos[tp]+len-1)){flg=1;return;}
		if((pos[tp]+=len)>c1[st[tp]]) --tp;
	}
	if(p<=c0[id]){flg=1;return;}
	if(c1[id]) st[++tp]=id,pos[tp]=1;
}
inline void slv(int l,int r){
	tp=flg=0;
	if(bl[l]==bl[r]){
		for(;l<=r;++l)
			if(a[l]>0) st[++tp]=a[l];
			else if(a[l]+st[tp]){printf("No\n");return;}
			else --tp;
		printf(tp?"No\n":"Yes\n");
		return;
	}
	for(b[cnt=1]=a[l++];bl[l]==bl[l-1];++l) b[++cnt]=a[l];
	build(bl[n]+1);push(bl[n]+1);
	for(;bl[l]<bl[r];l+=B) push(bl[l]);
	for(cnt=0;l<=r;++l) b[++cnt]=a[l];
	build(bl[n]+2);push(bl[n]+2);
	printf((flg||tp)?"No\n":"Yes\n");
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=pw[0]=1;i<=n;++i) scanf("%d",&a[i]),bl[i]=i/B+1,pw[i]=pw[i-1]*(k+1ll)%MOD;
	for(int i=1;i<=n;build(bl[i-1])) for(b[cnt=1]=a[i++];bl[i]==bl[i-1];++i) b[++cnt]=a[i];
	scanf("%d",&q);
	for(int opt,x,y;q--;){
		scanf("%d%d%d",&opt,&x,&y);
		if(opt==1){
			for(a[x]=y;bl[x-1]==bl[x];--x);
			for(b[cnt=1]=a[x++];bl[x]==bl[x-1];++x) b[++cnt]=a[x];
			build(bl[x-1]);
		}
		else slv(x,y);
	}
	return 0;
}