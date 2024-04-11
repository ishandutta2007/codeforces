#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e5+10,mod=1e9+7;
int pri[N],miu[N],phi[N],cnt,f[N];
bool np[N];
void sieve(int n){
	phi[1]=miu[1]=1;
	for(int i=2;i<=n;++i){
		if(!np[i])pri[++cnt]=i,miu[i]=-1,phi[i]=i-1;
		for(int j=1;j<=cnt&&i*pri[j]<=n;++j){
			np[i*pri[j]]=1;
			if(!(i%pri[j])){
				phi[i*pri[j]]=phi[i]*pri[j];
				break;
			}
			miu[i*pri[j]]=-miu[i];
			phi[i*pri[j]]=phi[i]*phi[pri[j]];
		}
	}
	for(int i=1;i<=n;++i)
		for(int j=i;j<=n;j+=i)
			f[j]+=i*miu[j/i];
}

int n,m,a[N],c[N];
ll ans=0;
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i],m=max(m,a[i]);
	sieve(max(n,m));
	int q=sqrt(n)*2.2;
	for(int d=1;d<=q;++d){
		memset(c,0,sizeof(c));
		ll sum=0;
		for(int i=d;i<=n;i+=d)++c[a[i]];
		for(int i=1;i<=(m>>1);++i)
			for(int j=i<<1;j<=m;j+=i)
				c[i]+=c[j];
		for(int i=1;i<=m;++i)
		    //sum+=(ll)c[i]*c[i]*phi[i];
			sum=(sum+(ll)c[i]*c[i]*phi[i])%mod;
		ans=(ans+sum%mod*f[d])%mod;
	}
	for(int d=q+1;d<=n;++d){
		ll sum=0;
		for(int i=d;i<=n;i+=d)
			for(int j=d;j<=n;j+=d)
				sum+=__gcd(a[i],a[j]);
		ans=(ans+sum%mod*f[d])%mod;
	}
	cout<<(ans%mod+mod)%mod<<endl;
}