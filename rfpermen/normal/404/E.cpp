#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
#define asd(i,n,N) for(int i=n;i< N;++i)
#define rap(i,n,N) for(int i=n;i>=N;--i)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define ff fi.fi
#define fs fi.se
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>> " << #x << " -> " << x << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define rng() ((rand()<<16)|rand())
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000000;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

int n,le,ri,mid,ans,nw,mn;
string s;

int main(){
// cout<<fixed<<setprecision(3);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
	if(s.back()=='R')for(auto &i:s){
    	if(i=='L')i = 'R';
    	else i = 'L';
	}
	n = s.size()-1;
    asd(i,0,n){
    	if(s[i]=='R')++nw;
    	else --nw, mn = min(mn,nw);
	}
	if(nw==mn)return cout<<"1\n",0;
	
	le = 1, ri = MOD;
	while(le<=ri){
		mid = le+ri>>1;
		mn = nw = 0;
		asd(i,0,n){
	    	if(s[i]=='R' && nw+1<mid)++nw;
	    	else if(s[i]=='L')--nw, mn = min(mn,nw);
		}
		
		if(nw==mn)ans = mid, le = mid+1;
		else ri = mid-1;
	}
	cout<<ans<<endl;
    return 0;
}