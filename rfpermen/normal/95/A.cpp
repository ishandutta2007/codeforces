#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define rap(i,n,N) for(ll i=n;i>=N;--i)
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
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl;
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define plll pair<ll,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 1e2+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll INF = 1e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;

int sz,n,tz;
string w[105],s;
bool chg[105];
char c;

inline bool cmp(char a,char b){
	if(a>='a')a = a-'a'+'A';
	if(b>='a')b = b-'a'+'A';
	return a!=b;
}

int main(){
//	cout<<fixed<<setprecision(15);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>w[i];
    cin>>s>>c;
    sz = s.size()-1;
    rep(i,1,n){
    	tz = w[i].size()-1;
    	rep(j,0,sz-tz){
    		rep(k,0,tz){
    			if(cmp(s[j+k],w[i][k]))break;
    			if(tz==k){
    				rep(o,0,tz)chg[j+o] = 1;
				}
			}
		}
	}
	rep(i,0,sz){
		if(chg[i]){
			if(cmp(s[i],c)){
				if(s[i]<='Z')s[i] = c-'a'+'A';
				else s[i] = c;
			}
			else {
				if(s[i]<='Z'){
					if(s[i]!='A')s[i] = 'A';
					else s[i] = 'B';
				}
				else {
					if(s[i]!='a')s[i] = 'a';
					else s[i] = 'b';
				}
			}
		}
	}
	cout<<s<<endl;
	return 0;
}