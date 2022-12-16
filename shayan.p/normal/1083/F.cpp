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

const int maxn=2e5+10, SQ=1000, MAX=(1<<14) + 10;

int cnt[SQ+10][MAX], lz[SQ+10];
vector<int> vec;

struct solver{
    vector<int> arr;// array
    vector<pii> qur;// queries
    vector<pii> ans;// ans[i]= delta change
    void solve(){
	int n= sz(arr), num=0;
	for(int i=0;i<n;i++){
	    arr[i]^= i==0 ? 0 : arr[i-1];
	    num+= arr[i]==0;
	}
	ans.PB({ num, arr[n-1]!=0 });

	for(int l=0;l<sz(qur);l+=SQ){
	    vec.clear();
	    
	    int r=min(l+SQ, sz(qur));
	    for(int i=l;i<r;i++){
		vec.PB(qur[i].F);
	    }
	    vec.PB(0);
	    sort(vec.begin(), vec.end());
	    vec.resize( unique( vec.begin(), vec.end() ) - vec.begin() );
    
	    int pt=0;
	    for(int i=0;i<n;i++){
		while(pt+1<sz(vec) && vec[pt+1]<=i) pt++;
		cnt[pt][arr[i]]++;
		lz[pt]=0;
	    }

	    for(int i=l;i<r;i++){
		for(int j= lower_bound( vec.begin(),  vec.end(), qur[i].F ) - vec.begin(); j<sz(vec); j++){
		    lz[j]^= qur[i].S;
		}
		int num=0;
		for(int j=0;j<sz(vec);j++){
		    num+= cnt[j][lz[j]];
		}
		ans.PB({ num, arr[n-1]!=lz[sz(vec)-1] });
	    }

	    pt=0;
	    for(int i=0;i<n;i++){
		while(pt+1<sz(vec) && vec[pt+1]<=i) pt++;
		cnt[pt][arr[i]]--;
		arr[i]^= lz[pt];
	    }
	}
	for(int i=sz(ans)-1;i>0;i--){
	    ans[i].F-= ans[i-1].F;
	    ans[i].S-= ans[i-1].S;
	}
    }    
};
solver slv[maxn];

int a[maxn], b[maxn];
pii toask[maxn][2];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n,k,q; cin>>n>>k>>q;

    for(int i=0;i<n;i++){
	cin>>a[i];
    }
    for(int i=0;i<n;i++){
	cin>>b[i];
    }
    for(int i=0;i<=n;i++){
	slv[i%k].arr.PB(a[i] ^ b[i] ^ (i==0 ? 0 : a[i-1] ^ b[i-1]));
    }
    for(int i=0;i<q;i++){
	char ch; int pos, y, x=0; cin>>ch>>pos>>y; pos--;
	if(ch=='a')
	    x=a[pos] ^ y, a[pos]=y;
	else
	    x=b[pos] ^ y, b[pos]=y;
	int r= pos % k;
	slv[r].qur.PB({pos/k, x});
	toask[i][0]= { r, sz(slv[r].qur) };
	
	r=(++pos)%k;
	slv[r].qur.PB({pos/k, x});
	toask[i][1]= { r, sz(slv[r].qur) };
    }
    
    int ans=0, bad=0;
    for(int i=0;i<k;i++){
	slv[i].solve();
	ans+= slv[i].ans[0].F;
	bad+= slv[i].ans[0].S;
    }
    if(bad==0)  cout<<n+1-ans<<"\n";
    else cout<<-1<<"\n";
    for(int i=0;i<q;i++){
	for(int j=0;j<2;j++){
	    pii p= toask[i][j];
	    ans+= slv[p.F].ans[p.S].F;
	    bad+= slv[p.F].ans[p.S].S;
	}
	if(bad==0) cout<<n+1-ans<<"\n";
	else cout<<-1<<"\n";
    }
    return 0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")