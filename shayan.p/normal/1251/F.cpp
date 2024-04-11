// Remember...

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

const int maxn=6e5+10, Lg=19, mod=(119<<23)+1;

int a[maxn], b[10], qq[maxn], ans[maxn];
int A[maxn], B[maxn], val[maxn], w[2][maxn];

int Pow(int a,int b){
    int ans=1;
    for(;b;b>>=1, a=1ll*a*a %mod)
	if(b&1) ans=1ll*ans*a %mod;
    return ans;
}
void prep(){
    w[0][0]=1;
    w[0][1]=Pow(3, (mod-1)>>Lg);
    int n=1<<Lg;
    for(int i=2;i<n;i++)
	w[0][i]= 1ll*w[0][i-1]*w[0][1] %mod;
    for(int i=1;i<n;i++)
	w[1][i]= w[0][(1<<Lg)-i];
    w[1][0]=1;
}
void fft(int *arr,bool inv){
    int n=1<<Lg;
    for(int i=0;i<n;i++){
	int x=0;
	for(int j=0;j<Lg;j++)
	    x+= bit(i,j)<<(Lg-1-j);
	if(x<i) swap(arr[i],arr[x]);
    }
    for(int stp=0;stp<Lg;stp++){
	int ln=1<<stp;
	for(int l=0;l<n;l+=ln+ln){
	    for(int i=0;i<ln;i++){
		int &a= arr[l+i], &b= arr[l+ln+i], c=1ll*b*w[inv][i<<(Lg-1-stp)] %mod;
		b= (a-c) %mod;
		a= (a+c) %mod;		
	    }
	}
    }
    if(inv){
	int num= Pow(1<<Lg,mod-2);
	for(int i=0;i<n;i++)
	    arr[i]= 1ll*arr[i]*num %mod;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    prep();
    
    int n,m; cin>>n>>m;
    for(int i=0;i<n;i++)
	cin>>a[i];
    for(int i=0;i<m;i++)
	cin>>b[i];
    int q; cin>>q;
    for(int i=0;i<q;i++)
	cin>>qq[i], qq[i]/=2;
    sort(a,a+n), sort(b,b+m);
    
    A[0]=1, A[1]=2;
    B[0]=1, B[1]=2, B[2]=1;
    fft(A,0), fft(B,0);

    for(int i=0;i<m;i++){
	int pt=0, ca=0, cb=0;
	while(pt<n && a[pt]<b[i]){
	    bool b1= pt==0 || a[pt-1]!=a[pt];
	    bool b2= pt==n-1 || a[pt+1]!=a[pt];
	    ca+= b1 && b2;
	    cb+= (!b1) && b2;
	    pt++;
	}
	for(int j=0;j<maxn;j++)
	    val[j]= 1ll*Pow(A[j],ca)*Pow(B[j],cb) %mod;
	fft(val,1);
	if(ca==0 && cb==0) memset(val,0,sizeof val), val[0]=1;
	for(int j=0;j<q;j++)
	    ans[j]= ( ans[j] + ( qq[j]-b[i]-1<0 ? 0 : val[ qq[j]-b[i]-1 ] ) ) %mod;
    }
    for(int i=0;i<q;i++){
	cout<<(ans[i]+mod)%mod<<"\n";
    }
    return 0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")