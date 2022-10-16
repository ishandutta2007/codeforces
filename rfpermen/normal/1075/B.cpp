#include <bits/stdc++.h>

#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define ull unsigned long long
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
const int MAX=2e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);
const double EPS = 1e-9;

ll n,x[MAX],y[MAX],z[MAX],m,k,id,cnt,a,b;
bool st;

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m; k = n+m;
    rep(i,1,k)cin>>z[i];
    rep(i,1,k){
    	cin>>st;
    	if(!st)x[++a] = z[i];
    	else y[++b] = z[i];
	}
	y[m+1] = 1e18, id = 1;
	rep(i,1,n){
		while(abs(y[id+1]-x[i])<abs(y[id]-x[i])){
			cout<<cnt<<' ';
			cnt = 0, id++;
		}
		cnt++;
	}
	while(id<=m)cout<<cnt<<' ', cnt = 0, id++;
    return 0;
}