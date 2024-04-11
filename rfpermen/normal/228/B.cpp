#include <bits/stdc++.h>

#pragma GCC optimize("O3")
using namespace std;
#define ll long long
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
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<piii,pii>
#define endl "\n"
const ll MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};

int n,m,mx,cnt,x,y,r,c,c1,c2,c3,c4;
char a[55][55],b[55][55];

int main(){
	cout<<fixed<<setprecision(0);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    rep(i,1,n)rep(j,1,m)cin>>a[i][j];
    cin>>r>>c;
    rep(i,1,r)rep(j,1,c)cin>>b[i][j];
    c1 = 1-n, c2 = r-1, c3 = 1-m, c4 = c-1;
    rep(i,c1,c2)rep(j,c3,c4){
    	cnt = 0;
    	rep(k,1,n)rep(o,1,m){
    		if(i+k<1 || i+k>r)continue;
    		if(j+o<1 || j+o>c)continue;
    		if(a[k][o]=='1' && b[i+k][j+o]=='1')cnt++;
		}
		//cout<<cnt<<" "<<i<<" "<<j<<endl;
		if(mx<cnt)mx = cnt, x = i, y = j;
	}
	cout<<x<<" "<<y;
    return 0;
}