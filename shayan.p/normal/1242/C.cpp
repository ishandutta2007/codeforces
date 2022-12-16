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

const int maxn=5000 * 15 + 10, MAX= 1<<15;

ll sm[20];
map<int,int> who;
int box[maxn], f[maxn];

vector<int> vec, vv;

int mark[maxn], C;

vector<int> vmsk[MAX];
int dp[MAX];

pii ans[20];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n; cin>>n;

    ll SM=0;
    
    for(int i=0;i<n;i++){
	int cnt; cin>>cnt;
	while(cnt--){
	    int x; cin>>x;
	    who[x]=sz(vec);
	    box[sz(vec)]=i;
	    vec.PB(x);
	    sm[i]+=x;
	    SM+=x;
	}
    }
    if(SM % n !=0) return cout<<"No\n",0;
    SM/=n;

    for(int i=0;i<sz(vec);i++){
	ll num= SM -sm[ box[i] ] +vec[i];
	if(who.count(num)==0) f[i]=-1;
	else f[i]= who[num];
    }
    for(int i=0;i<sz(vec);i++){
	++C;
	int tmp=i;
	while(tmp!=-1 && mark[tmp]==0){
	    mark[tmp]=C;
	    tmp=f[tmp];
	}
	if(tmp==-1) continue;
	if(mark[tmp]!=C) continue;
	
	vv.clear(), vv.PB(tmp);
	int frs=tmp;
	tmp=f[tmp];
	while(tmp != frs){
	    vv.PB(tmp);
	    tmp=f[tmp];
	}

	ll msk=0;
	for(int x:vv){
	    int id= box[x];
	    if(bit(msk,id)){
		msk=-1;
		break;
	    }
	    msk|= 1<<id;
	}
	if(msk!=-1){
	    vmsk[msk]=vv;
	}
    }
    memset(dp,-1,sizeof dp);
    
    dp[0]=-2;
    
    for(int msk=1;msk<(1<<n);msk++){
	if(vmsk[msk].empty()) continue;
	int X=((1<<n)-1) ^ msk;
	for(int msk2= X; ; msk2= (msk2-1) & X){
	    if(dp[msk2]!=-1 && dp[msk2 ^ msk]==-1)
		dp[msk2 ^ msk]=msk;
	    if(msk2==0) break;
	}
    }
    int msk=(1<<n)-1;
    if(dp[msk]==-1) return cout<<"No\n",0;

    while(msk!=0){
	int m=dp[msk];
	for(int i=0;i<sz(vmsk[m]);i++){
	    int A=box[vmsk[m][i]], B=box[ vmsk[m][ (i-1+sz(vmsk[m])) % sz(vmsk[m]) ] ];
	    ans[A]={ vec[ vmsk[m][i] ], B };					 
	}
	msk^= m;
    }

    cout<<"Yes\n";
    
    for(int i=0;i<n;i++){
	cout<<ans[i].F<<" "<<ans[i].S+1<<"\n";
    }
    return 0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")