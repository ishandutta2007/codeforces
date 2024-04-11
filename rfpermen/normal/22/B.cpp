#include <bits/stdc++.h>

#pragma GCC optimize("O3")
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
#define w fi
#define sf se.fi
#define ss se.se
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define pdi pair<double,int>
#define endl "\n"
const ll MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,-1,0,0,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1};

int n,m,x[26][26],mx;
char c;
int main(){
	//cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    rep(i,1,n)rep(j,1,m){
    	cin>>c;
    	x[i][j] = -x[i-1][j-1] + x[i-1][j] + x[i][j-1] + c-'0';
	}
	rep(i,1,n)rep(j,i,n){
		rep(a,1,m)rep(b,a,m){
			//cout<<i<<" "<<j<<" "<<a<<" "<<b<<" "<<x[j][b]-x[i-1][b]-x[j][a-1]+x[i-1][a-1]<<endl;
			if(x[j][b]-x[i-1][b]-x[j][a-1]+x[i-1][a-1])continue;
			mx = max(mx,(j-i+1+b-a+1)*2);
		}
	}
	cout<<mx<<endl;
    return 0;
}