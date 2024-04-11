#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
//#pragma GCC optimize("unroll-loops")
 
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
//#define ff fi.fi
//#define fs fi.se
//#define sf se.fi
//#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>> " << #x << " -> " << (x) << endl
#define out(x,y) cout << ">> " << (x) << " " << (y) << endl
#define mems(x,y) memset(x,y,sizeof x)
#define all(x) x.begin(),x.end()
#define rng() ((rand()<<16)|rand())
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<ll,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 2e5+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 9e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 500;

int q,n,m,lps[1005],pf[MAX],sf[MAX],ans,nw;
string s,rs,t;

int main(){
//	cout<<fixed<<setprecision(10);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    n = s.size();
    rs = s;
    reverse(all(rs));
    cin>>q;
    while(q--){
    	cin>>t;
    	m = t.size();
    	if(m==1)continue;
    	nw = 0;
    	asd(i,1,m){
    		while(nw && t[nw]!=t[i])nw = lps[nw-1];
    		if(t[nw]==t[i])lps[i] = ++nw;
    		else lps[i] = 0;
		}
		nw = 0;
		asd(i,0,n){
    		while(nw && t[nw]!=s[i])nw = lps[nw-1];
    		if(t[nw]==s[i])++nw;
    		if(nw==m)break;
    		pf[i] = nw;
		}
		if(nw==m){++ans; continue;}
		reverse(all(t));
    	nw = 0;
    	asd(i,1,m){
    		while(nw && t[nw]!=t[i])nw = lps[nw-1];
    		if(t[nw]==t[i])lps[i] = ++nw;
    		else lps[i] = 0;
		}
		nw = 0;
		asd(i,0,n){
    		while(nw && t[nw]!=rs[i])nw = lps[nw-1];
    		if(t[nw]==rs[i])++nw;
    		sf[n-i-1] = nw;
		}
		rap(i,n-1,0)sf[i] = max(sf[i],sf[i+1]);
		asd(i,0,n){
			if(pf[i]+sf[i+1]>=m){
				++ans;
				break;
			}
		}
	}
	cout<<ans<<endl;
    return 0;
}