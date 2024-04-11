#include <bits/stdc++.h>

#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl;
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX=1<<19;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);
const double EPS = 1e-9;

int n,dp[MAX][4];
string s,o = "BGR";

inline int ch(char c){
	if(c=='B')return 0;
	if(c=='G')return 1;
	return 2;
}

int f(int nw,int ls){
	if(nw==n)return dp[nw][ls] = 0;
	if(dp[nw][ls]!=-1)return dp[nw][ls];
	int ret = 1e9;
	rep(i,0,2){
		if(ls==i)continue;
		if(i==ch(s[nw]))ret = min(ret,f(nw+1,i));
		else ret = min(ret,f(nw+1,i)+1);
	}
	return dp[nw][ls] = ret;
}

void bt(int nw,int ls){
	if(nw==n)return;
	rep(i,0,2){
		if(ls==i)continue;
		if(i==ch(s[nw])){
			if(dp[nw][ls]==dp[nw+1][i]){
				cout<<o[i];
				bt(nw+1,i);
				return;
			}
		}
		else if(dp[nw][ls]==dp[nw+1][i]+1){
			cout<<o[i];
			bt(nw+1,i);
			return;
		}
	}
}

int main(){
	cout<<fixed<<setprecision(6);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>s;
    memset(dp,-1,sizeof dp);
    cout<<f(0,3)<<endl;
    bt(0,3);
    return 0;
}