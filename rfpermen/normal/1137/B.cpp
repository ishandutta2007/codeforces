#include<bits/stdc++.h>
 
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
const int MAX = 5e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

int m,a,b,lps[MAX],nw;
string s,t;

int main(){
// cout<<fixed<<setprecision(10);
// freopen("input.txt", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s>>t;
    for(char c:s){
    	if(c=='0')++a;
    	else ++b;
	}
	m = t.size();
	
	asd(i,1,m){
		while(nw && t[nw]!=t[i])nw = lps[nw-1];
		if(t[nw]==t[i])++nw;
		lps[i] = nw;
	}
	
	nw = 0;
	while(1){
		if(t[nw]=='0'){
			if(!a)break;
			cout<<'0', ++nw, --a;
		}
		else {
			if(!b)break;
			cout<<'1', ++nw, --b;
		}
		if(nw==m)nw = lps[nw-1];
	}
	while(a--)cout<<'0';
	while(b--)cout<<'1';
	cout<<endl;
    return 0;
}