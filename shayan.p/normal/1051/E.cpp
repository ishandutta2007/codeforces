// Can U hack it?

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)
#define qqq(a) cerr<<"error "<<a<<endl;
#define FOR(i,a,b) for(int i=int(a);i<=int(b);i++)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=1e6+10;
const ll mod=998244353,P1=73,P2=31;

ll dp[maxn],sm[maxn],tw1[maxn],tw2[maxn];
pll hsh[maxn],hshl[maxn],hshr[maxn];

string A,L,R;

int n,nl,nr;

inline pll HSH(int l,int r){
    ll A=(hsh[r].F-(l==0?0:hsh[l-1].F)*tw1[r-l+1])%mod;
    ll B=(hsh[r].S-(l==0?0:hsh[l-1].S)*tw2[r-l+1])%mod;
    if(A<0)A+=mod;
    if(B<0)B+=mod;
    return {A,B};
}

bool Comp1(int pos){
    int l=pos,r=pos+nl-1,ans=-1;
    while(l<=r){
	int mid=(l+r)/2;
	if(HSH(pos,mid)==hshl[mid-pos])
	    l=mid+1;
	else
	    ans=mid,r=mid-1;
    }
    if(ans==-1)return 1;
    return L[ans-pos]<A[ans];
}

bool Comp2(int pos){
    int l=pos,r=pos+nr-1,ans=-1;
    while(l<=r){
	int mid=(l+r)/2;
	if(HSH(pos,mid)==hshr[mid-pos])
	    l=mid+1;
	else
	    ans=mid,r=mid-1;
    }
    if(ans==-1)return 1;
    return R[ans-pos]>A[ans];
}

int main(){
    tw1[0]=tw2[0]=1;
    FOR(i,1,maxn-1){
	tw1[i]=(tw1[i-1]*P1)%mod;
	tw2[i]=(tw2[i-1]*P2)%mod;
    }
    
    cin>>A>>L>>R;

    dp[0]=sm[0]=1;
    n=sz(A);
    nl=sz(L);
    nr=sz(R);

    hsh[0]={A[0]-'0'+1,A[0]-'0'+1};
    FOR(i,1,n-1){
	hsh[i].F=(hsh[i-1].F*P1+A[i]-'0'+1)%mod;
	hsh[i].S=(hsh[i-1].S*P2+A[i]-'0'+1)%mod;
    }
    
    hshl[0]={L[0]-'0'+1,L[0]-'0'+1};
    FOR(i,1,nl-1){
	hshl[i].F=(hshl[i-1].F*P1+L[i]-'0'+1)%mod;
	hshl[i].S=(hshl[i-1].S*P2+L[i]-'0'+1)%mod;
    }


    hshr[0]={R[0]-'0'+1,R[0]-'0'+1};
    FOR(i,1,nr-1){
	hshr[i].F=(hshr[i-1].F*P1+R[i]-'0'+1)%mod;
	hshr[i].S=(hshr[i-1].S*P2+R[i]-'0'+1)%mod;
    }
    
    FOR(i,1,n){
	int ind1=i-nl-1,ind2=i-nr+1;
	if(nl==nr){
	    if(i>=nl && (nl==1 || A[i-nl]!='0') && Comp1(i-nl) && Comp2(i-nr) )
		dp[i]+=dp[i-nl];
	}
	else if((nr-nl)==1){
	    if(i>=nl && (nl==1 || A[i-nl]!='0') && Comp1(i-nl))
		dp[i]+=dp[i-nl];
	    if(i>=nr && (nr==1 || A[i-nr]!='0') && Comp2(i-nr))
		dp[i]+=dp[i-nr];
	}
	else{
	    if(ind1>=0)
		dp[i]+=sm[ind1]-(ind2<=0?0:sm[ind2-1]);
	    if(i>=nl && (nl==1 || A[i-nl]!='0') && Comp1(i-nl))
		dp[i]+=dp[i-nl];
	    if(i>=nr && (nr==1 || A[i-nr]!='0') && Comp2(i-nr))
		dp[i]+=dp[i-nr];
	}
	dp[i]%=mod;
	sm[i]=(sm[i-1]+((i<n && A[i]=='0')?0:dp[i]))%mod;
    }
    cout<<(dp[n]+mod)%mod<<endl;
}