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

const int Log=16,M1=1<<(Log-1),M2=1<<Log,mod=998244353,magic=(mod-1)>>Log;

map<int,vector<int> >dp;
int w[M2],wh[M2],rvt=1;

int Pow(int a,int b){
    int ans=1;
    while(b){
	if(b&1) ans=1ll*ans*a%mod;
	a=1ll*a*a %mod;
	b>>=1;
    }
    return ans;
}

void ntt(vector<int>&a,bool rev){
    for(int i=0;i<sz(a);i++) if(i<wh[i]) swap(a[i],a[wh[i]]);
    for(int LN1=2,LN2=1;LN2<M2;LN1<<=1,LN2<<=1){
	int t=(rev?-1:1)*M2/LN1;
	if(t<0) t+=M2;
	for(int st=0;st<M2;st+=LN1){
	    int id=0;
	    for(int i=st;i<st+LN2;i++){
		int &A=a[i],&B=a[i+LN2],x=1ll*B*w[id] %mod;
		id=(id+t);
		if(id>=M2) id-=M2;
		B=A-x;
		if(B<0) B+=mod;
		if(B>=mod) B-=mod;
		A=A+x;
		if(A<0) A+=mod;
		if(A>=mod) A-=mod;
	    }
	}
    }
    if(rev){
	for(int &x:a)
	    x=1ll*x*rvt %mod;
    }
}

void calc(int n){
    if(dp.count(n)) return;
    if(n&1){
	calc((n+1)/2);calc((n-1)/2);calc((n-3)/2);
	vector<int>A=dp[(n+1)/2],B=dp[(n-1)/2],C=dp[(n-3)/2];
	ntt(A,0);ntt(B,0);ntt(C,0);
	for(int i=0;i<M2;i++)
	    A[i]=1ll*A[i]*B[i] %mod;
	for(int i=0;i<M2;i++)
	    B[i]=1ll*B[i]*C[i] %mod;
	ntt(A,1);ntt(B,1);
	for(int i=1;i<M2;i++)
	    C[i]=(A[i]+B[i-1]) %mod;
	C[0]=A[0];
	dp[n]=C;
    }
    else{
	calc(n/2);calc((n-2)/2);
	vector<int>A=dp[n/2],B=dp[(n-2)/2];
	ntt(A,0);ntt(B,0);
	for(int i=0;i<M2;i++)
	    A[i]=1ll*A[i] * A[i] %mod;
	for(int i=0;i<M2;i++)
	    B[i]=1ll*B[i] * B[i] %mod;
	ntt(A,1);ntt(B,1);
	for(int i=1;i<M2;i++)
	    A[i]=(A[i]+B[i-1]) %mod;
	dp[n]=A;
    }
    vector<int>&vec=dp[n];
    for(int i=M1;i<M2;i++)
	vec[i]=0;
}

int main(){
    w[0]=1;w[1]=1;
    for(int i=0;i<magic;i++)
	w[1]=3ll*w[1] %mod;
    for(int i=2;i<M2;i++)
	w[i]=1ll*w[i-1]*w[1] %mod;
    for(int i=1;i<M2;i++){
	for(int j=0;j<Log;j++)
	    wh[i]+=bit(i,j)<<(Log-1-j);
    }
    int X=(mod+1)/2;
    for(int i=0;i<Log;i++)
	rvt=1ll*rvt*X %mod;
    dp[0].resize(M2);
    dp[1].resize(M2);
    dp[2].resize(M2);
    
    dp[0][0]=1;
    dp[1][0]=1;dp[1][1]=1;
    dp[2][0]=1;dp[2][1]=3;dp[2][2]=1;

    int n,k;cin>>n>>k;
    calc(n);
    vector<int>Ans=dp[n];
    for(int i=1;i<=k;i++)
	cout<<((Ans[i]+mod)%mod)<<" ";
    cout<<endl;
    return 0;
}