#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define rap(i,n,N) for(ll i=n;i>=N;--i)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
//#define ff fi.fi
//#define fs fi.se
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cerr << ">>>>>> " << #x << " -> " << x << endl
#define nani(x) cerr <<  "Line " << __LINE__ << ": " << #x << " is " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 2e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

ll tc,n,sz,x,l[MAX],r[MAX],le,ri,mid,ans,tmp,tgt;
priority_queue<ll> pq;
 
int main(){
//	cout<<fixed<<setprecision(4);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>tc;
    while(tc--){
    	cin>>n>>x; sz = (n+1)/2;
    	rep(i,1,n)cin>>l[i]>>r[i];
    	le = 0, ri = 1e15, ans = -1;
    	while(le<=ri){
    		mid = le+ri>>1;
    		tgt = sz, tmp = 0;
    		while(!pq.empty())pq.pop();
    		rep(i,1,n){
    			tmp+=l[i];
    			if(r[i]<mid)continue;
    			if(l[i]>=mid)tgt--;
    			else pq.push(mid-l[i]);
			}
			if(pq.size()<tgt)ri = mid-1;
			else {
				while(!pq.empty()&&pq.size()>tgt)pq.pop();
				while(!pq.empty())tmp+=pq.top(), pq.pop();
				if(tmp<=x)ans = mid, le = mid+1;
				else ri = mid-1;
			}
		}
		cout<<ans<<endl;
	}
    return 0;
}