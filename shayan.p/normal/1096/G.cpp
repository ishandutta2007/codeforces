// Phoenix

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

const int mod=998244353,W=3;

int Pow(int a,int b){
    int ans=1;
    while(b>0){
	if(b&1) ans=(1ll*ans*a)%mod;
	a=(1ll*a*a)%mod;
	b>>=1;
    }
    return ans;
}
void ntt(vector<int>&a,bool rev){
    if(sz(a)==0) return;
    int n=32-__builtin_clz(sz(a));
    if((1<<(n-1))==sz(a)) --n;
    a.resize(1<<n);
    vector<int>w(1<<n);
    w[0]=1;w[1]=Pow(W,(mod-1)>>n);	
    for(int i=2;i<(1<<n);i++)
	w[i]=1ll*w[i-1]*w[1] %mod;
    for(int i=0;i<sz(a);i++){
	int x=0;
	for(int j=0;j<n;j++)
	    x+=bit(i,j)<<(n-1-j);
	if(i<x)
	    swap(a[i],a[x]);
    }
    int N=(1<<n);
    for(int ln1=1,ln2=ln1-1,LN1=(1<<ln1),LN2=(1<<ln2);ln1<=n;ln1++,ln2++,LN1<<=1,LN2<<=1){
	int t=(rev?-1:1)<<(n-ln1);
	if(t<0) t+=N;
	for(int st=0;st<sz(a);st+=LN1){
	    int id=0;
	    for(int i=st;i<st+LN2;i++){
		int &A=a[i],&B=a[i+LN2],x=1ll*B*w[id] %mod;
		id=(id+t);
		if(id>=N) id-=N;
		B=A-x;
		if(B<0) B+=mod;
		if(B>=mod) B-=mod;
		A=A+x;
		if(A<0) A+=mod;
		if(A>=mod) A-=mod;
	    }
	}
    }
    int rvt=Pow(2,mod-n-1);
    if(rev){
	for(int &x:a)
	    x=1ll*x*rvt %mod;
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,k;cin>>n>>k; n>>=1;
    vector<int>a(9*n+1);
    for(int i=0;i<k;i++){
	int x;cin>>x;
	++a[x];
    }
    ntt(a,0);
    for(int &x:a)
	x=Pow(x,n);
    ntt(a,1);
    int ans=0;
    for(int &x:a)
	ans=(1ll*ans+1ll*x*x)%mod;
    cout<<ans<<endl;
    return 0;
}