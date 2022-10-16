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
const int MAX = 1e2+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

int sz,tz,vz,dp[MAX][MAX][MAX],pr[MAX][128];
string s,t,v;

int f(int a,int b,int c){
	if(c>vz)return -1e9;
	if(a==sz||b==tz)return 0;
	if(dp[a][b][c]!=-1)return dp[a][b][c];
	int ret = max(f(a+1,b,c),f(a,b+1,c));
	if(s[a]==t[b])ret = max(ret,f(a+1,b+1,pr[c][s[a]])+1);
	return dp[a][b][c] = ret;
}

void bt(int a,int b,int c){
	if(a==sz||b==tz)return;
	if(dp[a][b][c]==f(a+1,b,c))bt(a+1,b,c);
	else if(dp[a][b][c]==f(a,b+1,c))bt(a,b+1,c);
	else if(dp[a][b][c]==f(a+1,b+1,pr[c][s[a]])+1)cout<<s[a], bt(a+1,b+1,pr[c][s[a]]);
}

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s>>t>>v;
    sz = s.size(), tz = t.size(), vz = v.size()-1;
    int id;
    rep(i,0,vz){
    	rep(j,'A','Z'){
    		rep(k,0,i){
    			id = 0;
    			rep(o,k,i-1){
    				if(v[id]==v[o])++id;
    				else {id = -1; break;}
				}
				if(id!=-1 && v[id]==j){
					pr[i][j] = id+1;
					break;
				}
			}
		}
	}
    memset(dp,-1,sizeof dp);
    if(!f(0,0,0))cout<<0;
    else bt(0,0,0);
    return 0;
}