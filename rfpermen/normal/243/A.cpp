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
#define pll pair<int,ll>
#define piii pair<int,pii>
#define piiii pair<piii,pii>
//#define endl "\n"
const ll MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};

int n,x[MAX],cnt,nw,mx;
bool vis[1<<21];
set<int> s[MAX];

int main(){
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>x[i];
    mx = (1<<21)-1;
    rep(i,1,n){
    	nw = x[i];
    	if(s[i].count(nw))continue;
    	s[i].insert(nw);
    	vis[nw] = 1;
    	rep(j,i+1,n){
    		nw|=x[j];
    		if(s[j].count(nw))break;
    		s[j].insert(nw);
    		vis[nw] = 1;
		}
	}
	rep(i,0,mx)cnt+=vis[i];
	cout<<cnt<<endl;
    return 0;
}