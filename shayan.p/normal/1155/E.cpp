// Faster!

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=1e5+10,mod=1e6+3;

vector<int>v[20];
int ans[20];

vector<int> operator - (vector<int> a,vector<int> b){
    for(int i=0;i<sz(a);i++)
	a[i]=(a[i]-b[i])%mod;
    return a;
}
vector<int> operator * (vector<int> a,int num){
    for(int i=0;i<sz(a);i++)
	a[i]=1ll*a[i]*num %mod;
    return a;
}
int Pow(int a,int b){
    int ans=1;
    for(;b;b>>=1,a=1ll*a*a %mod){
	if(b&1) ans=1ll*ans*a %mod;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    for(int i=0;i<19;i++){
	for(int j=0,num=1;j<19;num=1ll*num*i % mod,j++){
	    v[i].PB(num);
	}
	cout<<"? "<<i<<endl;
	int x;cin>>x;
	v[i].PB(x);
    }
    for(int i=0;i<19;i++){
	for(int j=i;j<19;j++)
	    if(v[i][j]!=0) swap(v[i],v[j]);
	assert(v[i][i]!=0);
	int num=Pow(v[i][i],mod-2);
	v[i]=v[i]*num;
	for(int j=0;j<19;j++){
	    if(i!=j && v[j][i]!=0)
		v[j]=v[j] - (v[i] * v[j][i]);
	}
    }
    for(int i=0;i<19;i++){
	ans[i]=v[i][19];
    }
    for(int i=0;i<mod;i++){
	int num=0;
	for(int j=0,x=1;j<19;x=1ll*x*i %mod,j++)
	    num=(1ll*num+1ll*x*ans[j])%mod;
	if(num==0) return cout<<"! "<<i<<endl,0;
    }
    return cout<<"! "<<-1<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.