#include <bits/stdc++.h>

#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define rep(i,n,N) for(int i=n;i<=N;i++)
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
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);
const double eps = 1e-9;

int n,x[MAX];
bool vis[MAX][6], dp[MAX][6];

bool f(int nw,int ls){
	if(nw>n)return dp[nw][ls] = 1;
	if(vis[nw][ls])return dp[nw][ls];
	vis[nw][ls] = 1;
	bool ret = 0;
	if(x[nw]==x[nw-1]){
		rep(i,1,5){
			if(i==ls)continue;
			ret|=f(nw+1,i);
		}
	}
	else if(x[nw]<x[nw-1]){
		rep(i,1,ls-1)ret|=f(nw+1,i);
	}
	else {
		rep(i,ls+1,5)ret|=f(nw+1,i);
	}
	return dp[nw][ls] = ret;
}

void bt(int nw,int ls){
	if(nw>n)return;
	if(x[nw]==x[nw-1]){
		rep(i,1,5){
			if(i==ls)continue;
			if(dp[nw+1][i]){
				cout<<i<<' ';
				bt(nw+1,i);
				break;
			}
		}
	}
	else if(x[nw]<x[nw-1]){
		rep(i,1,ls-1)if(dp[nw+1][i]){
				cout<<i<<' ';
				bt(nw+1,i);
				break;
			}
	}
	else {
		rep(i,ls+1,5)if(dp[nw+1][i]){
				cout<<i<<' ';
				bt(nw+1,i);
				break;
			}
	}
	return;
}

int main(){
//	cout<<fixed<<setprecision(3);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>x[i];
    if(!f(1,0))return cout<<-1,0;
    bt(1,0);
    return 0;
}