#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=n;i<=N;++i)
#define rap(i,n,N) for(int i=n;i>=N;--i)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
//#define ff fi.fi
//#define fs fi.se
//#define sf se.fi
//#define ss se.se
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
const int MAX = 1e3+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

int rem,dv,sz,tz,id,nw,st,hit,cnt,ans;
pii sta[105][105];
bool vis[128];
string s,t;

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>rem>>dv;
    cin>>s>>t;
    for(auto i:s)vis[i] = 1;
    for(auto i:t)if(!vis[i])return cout<<0,0;
    sz = s.size(), tz = t.size();
    rep(i,0,sz)if(s[i]==t[0]){
    	st = i;
    	break;
	}
	nw = st;
	memset(sta,-1,sizeof sta);
	while(1){
		++id; if(id==tz)id = 0, ++hit, ++ans;
		do{
			++nw;
			if(nw==sz){
				nw = 0, ++cnt, --rem;
				if(!rem)return cout<<hit/dv,0;
			}
		}while(s[nw]!=t[id]);
		
		if(!id && sta[nw][id].fi!=-1){
			cnt-= sta[nw][id].fi;
			hit-= sta[nw][id].se;
			break;
		}
		sta[nw][id] = {cnt,hit};
	}
	ans+= rem/cnt*hit;
	rem%= cnt;
	rem+= cnt;
	ans-= hit;
	cnt = 0;
	while(1){
		++id; if(id==tz)id = 0, ++ans;
		do{
			++nw;
			if(nw==sz){
				nw = 0, ++cnt;
				if(rem==cnt)return cout<<ans/dv,0;
			}
		}while(s[nw]!=t[id]);
	}
    return 0;
}