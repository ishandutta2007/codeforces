#include <map>
#include <cstdio>
#include <iostream>
using namespace std;
const int Maxn=5000000;
typedef long long ll;
bool np[Maxn+5];
int p[Maxn+5],p_len;
int mu[Maxn+5];
void init(){
	np[0]=np[1]=1;
	mu[1]=1;
	for(int i=2;i<=Maxn;i++){
		if(!np[i]){
			p[++p_len]=i;
			mu[i]=-1;
		}
		for(int j=1,x;1ll*i*p[j]<=Maxn;j++){
			x=i*p[j];
			np[x]=1;
			if(i%p[j]==0){
				mu[x]=0;
				break;
			}
			mu[x]=-mu[i];
		}
	}
}
ll a,m;
ll k;
map<ll,int> sm;
ll gcd(ll a,ll b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}
int find_mu(ll n){
	if(n<=Maxn){
		return mu[n];
	}
	if(sm.count(n)>0){
		return sm[n];
	}
	int num=0;
	for(ll i=2;i*i<=n;i++){
		if(n%i==0){
			num++;
			n/=i;
			if(n%i==0){
				return sm[n]=0;
			}
		}
	}
	if(n>1){
		num++;
	}
	if(num&1){
		return sm[n]=-1;
	}
	return sm[n]=1;
}
ll work(ll m,ll n){
	ll ans=0;
	for(ll i=1;i*i<=m;i++){
		if(m%i==0){
			ans+=find_mu(i)*(n/i);
			if(i*i<m){
				ans+=find_mu(m/i)*(n/(m/i));
			}
		}
	}
	return ans;
}
ll find_phi(ll n){
	ll ans=n;
	for(ll i=2;i*i<=n;i++){
		if(n%i==0){
			ans=ans/i*(i-1);
			while(n%i==0){
				n/=i;
			}
		}
	}
	if(n>1){
		ans=ans/n*(n-1);
	}
	return ans;
}
int main(){
	init();
	int t;
	scanf("%d",&t);
	while(t--){
		cin>>a>>m;
		k=gcd(a,m);
		cout<<find_phi(m/k)<<endl;
//		cout<<work(m/k,m/k)<<endl;
	}
	return 0;
}