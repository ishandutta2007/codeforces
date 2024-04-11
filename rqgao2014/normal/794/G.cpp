#include<bits/stdc++.h>
#define sqr(x) ((ll)(x)*(x)%mod)
#define ll long long
using namespace std;

const int N=300005,mod=1e9+7;
inline void ch(int &x,int y){x=(x+y)%mod;}
inline int exp(int x,int y){
	int ans=1;while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}return ans;
}

char c[N],d[N];
int fac[N<<1],ifac[N<<1],pw[N],phi[N],p[N],tot;
int cc,dd,rc,rd,ac,bc,ad,bd,n,ans;
bool vis[N];

inline int C(int x,int y){
	if(x<y||y<0) return 0;
	return (ll)fac[x]*ifac[y]%mod*ifac[x-y]%mod;
}
int main(){
	n=600000;
	fac[0]=ifac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=(ll)fac[i-1]*i%mod;
	ifac[n]=exp(fac[n],mod-2);
	for(int i=n-1;i;i--) ifac[i]=(ll)ifac[i+1]*(i+1)%mod;
	n/=2;pw[0]=1;
	for(int i=1;i<=n+3;i++) pw[i]=pw[i-1]*2%mod;
	phi[1]=1;
	for(int i=2;i<=n;i++){
		if(!vis[i]){p[++tot]=i;phi[i]=i-1;}
		for(int j=1;j<=tot&&p[j]*i<=n;j++){
			vis[i*p[j]]=1;
			if(i%p[j]==0){
				phi[i*p[j]]=phi[i]*p[j];
				break;
			}
			phi[i*p[j]]=phi[i]*(p[j]-1);
		}
		ch(phi[i],phi[i-1]);
	}
	scanf("%s%s%d",c+1,d+1,&n);
	rc=cc=strlen(c+1);rd=dd=strlen(d+1);
	for(int i=1;i<=cc;i++)
		if(c[i]=='A') ac++,rc--; else if(c[i]=='B') bc++,rc--;
	for(int i=1;i<=dd;i++)
		if(d[i]=='A') ad++,rd--; else if(d[i]=='B') bd++,rd--;
	if(cc==dd){
		int cnt=1,isok=1,res=0,p=0;
		for(int i=1;i<=cc;i++)
			if(c[i]+d[i]=='A'+'B') isok=0; else if(c[i]+d[i]=='?'*2) cnt=cnt*2%mod;
		cnt*=isok;
		for(int i=max(ac,ad);i<=min(cc-bc,dd-bd);i++)
			ch(p,(ll)C(rc,i-ac)*C(rd,i-ad)%mod);
		for(int d=1;d<=n;d++)
			ch(res,(ll)pw[d]*(phi[n/d]*2-1)%mod);
		ch(ans,(ll)res*(p-cnt+mod)%mod);
		ch(ans,(ll)cnt*sqr(pw[n+1]-2+mod)%mod);
	}
	for(int i=1;i<=cc;i++){
		int ai=i,aj=i-cc+dd,g;
		if(aj<=0) continue;
		g=__gcd(ai,aj);ai/=g;aj/=g;
		ch(ans,(ll)(C(rc+rd,rd-ac+ad+i)+C(rc+rd,rd-bc+bd+i))*(pw[n/max(ai,aj)+1]-2+mod)%mod);
	}
	printf("%d\n",ans);
	return 0;
}