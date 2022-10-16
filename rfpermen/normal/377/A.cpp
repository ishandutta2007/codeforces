#include <bits/stdc++.h>

#pragma GCC optimize("O2")
//#pragma GCC optimize("Ofast,no-stack-protector") 
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native") 
//#pragma GCC optimize("unroll-loops")
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
#define piiii pair<piii,pii>
#define endl "\n"
const ll MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};

int n,m,k,v[505][505],r,c,nr,nc;
char grid[505][505];
queue<pii> q;
vector<piii> res;
pii cur;

int main(){
	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    memset(v,-1,sizeof v);
    rep(i,1,n)rep(j,1,m)cin>>grid[i][j];
    rep(i,1,n){
    	if(r)break;
    	rep(j,1,m){
    		if(r)break;
    		if(grid[i][j]=='.')r = i, c = j;
		}
	}
	v[r][c] = 0;
	res.pb({0,{r,c}});
	q.push({r,c});
	while(!q.empty()){
		cur = q.front(); q.pop();
		r = cur.fi, c = cur.se;
		rep(i,0,3){
			nr = r+dr[i], nc = c+dc[i];
			if(grid[nr][nc]!='.')continue;
			if(v[nr][nc]!=-1)continue;
			res.pb({v[r][c]+1,{nr,nc}});
			v[nr][nc] = v[r][c]+1; 
			q.push({nr,nc});
		}
	}
	sort(res.begin(),res.end());
	reverse(res.begin(),res.end());
	for(auto i:res){
		if(k==0)break;
		grid[i.sf][i.ss] = 'X';
		k--;
	}
	rep(i,1,n){
		rep(j,1,m)cout<<grid[i][j]; cout<<endl;
	}
    return 0;
}