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
typedef unsigned long long ull;

const int maxn=2e7+10,mod=1e9+7;
const ull M=(1ll<<32)-1;

ull b[maxn],ans1,ans2;
ll a[maxn];
ull inf;
bool is1,is2;

void Do(ll a,ll b){
    if((a<0) ^ (b<0))
	ans2=max(ans2,ull(abs(a))*ull(abs(b))),is2=1;
    else
	ans1=min(ans1,ull(abs(a))*ull(abs(b))),is1=1;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    for(int i=0;i<64;i++)
	inf+=(1ll<<i);
    int t;cin>>t;
    while(t--){
	int n;ll l,r;ull x,y,z;cin>>n>>l>>r>>x>>y>>z>>b[0]>>b[1];
	for(int i=2;i<n;i++)
	    b[i]=(b[i-2]*x+b[i-1]*y+z)&M;
	for(int i=0;i<n;i++)
	    a[i]=(b[i]%(r-l+1))+l;
	ans1=inf;ans2=0;is1=0;is2=0;
      
	ll num=a[n-1];
	for(int i=n-2;i>=0;i--){
	    if(a[i]<num)
		Do(a[i],num);
	    num=max(num,a[i]);
	}
	num=a[n-1];
	for(int i=n-2;i>=0;i--){
	    if(a[i]<num)
		Do(a[i],num);
	    num=min(num,a[i]);
	}
	num=a[0];
	for(int i=1;i<n;i++){
	    if(num<a[i])
		Do(a[i],num);
	    num=max(num,a[i]);
	}
	num=a[0];
	for(int i=1;i<n;i++){
	    if(num<a[i])
		Do(a[i],num);
	    num=min(num,a[i]);
	}
	if(!is1 && !is2) cout<<"IMPOSSIBLE\n";
	else if(is2 && ans2>0) cout<<"-"<<ans2<<"\n";
	else if(is2 && ans2==0) cout<<"0\n";
	else cout<<ans1<<"\n";
    }
}