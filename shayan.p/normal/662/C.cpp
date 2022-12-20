// Can U hack it?

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

const int maxN=22,TW=(1<<20);

int n,m;
string s[maxN];
ll a[TW+10],b[TW+10];

void transform(ll *l,ll *r){
    if((r-l)==1)return;
    ll *mid=l+(r-l)/2;
    transform(l,mid);
    transform(mid,r);
    for(int i=0;i<(mid-l);i++){
	ll A=*(l+i),B=*(mid+i);
	*(l+i)=A+B;
	*(mid+i)=A-B;
    }
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++)
	cin>>s[i];
    for(int j=0;j<m;j++){
	int msk=0;
	for(int i=0;i<n;i++)
	    msk+=(s[i][j]=='1')<<i;
	a[msk]++;
    }
    for(int i=0;i<(1<<n);i++){
	b[i]=__builtin_popcount(i);
	b[i]=min(b[i],n-b[i]);
    }
    transform(a,a+TW);
    transform(b,b+TW);
    for(int i=0;i<TW;i++)
	a[i]*=b[i];
    transform(a,a+TW);
    for(int i=0;i<TW;i++)
	a[i]/=TW;
    int ans=n*m;
    for(int msk=0;msk<(1<<n);msk++){
	ans=min(ans,int(a[msk]));
    }
    cout<<ans<<endl;
}