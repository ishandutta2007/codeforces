#include <bits/stdc++.h>
 
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
const int MAX = 2e6+5;
const ll MAX2 = 11;
const ll MOD = 10007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 555;

int n,x[MAX],cnt;
bool p[MAX];

int main(){
// cout<<fixed<<setprecision(3);
// freopen("trip.in", "r", stdin);
// freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    rep(i,2,1414){
    	if(p[i])continue;
    	for(int j = i*i; j<=2000000; j+=i)p[j] = 1;
	}
	cin>>n;
	rep(i,1,n){
		cin>>x[i];
		if(x[i]==1)++cnt;
	}
	if(cnt){
		rep(i,1,n)if(x[i]!=1){
			if(!p[x[i]+1]){
				cout<<cnt+1<<endl;
				rep(j,1,cnt)cout<<"1 ";
				cout<<x[i]<<endl;
				return 0;
			}
		}
		if(cnt>1){
			cout<<cnt<<endl;
			rep(j,1,cnt)cout<<"1 ";
			cout<<endl;
			return 0;
		}
	}
	rep(i,1,n)rep(j,i+1,n)if(!p[x[i]+x[j]])return cout<<"2\n"<<x[i]<<' '<<x[j]<<endl,0;
	cout<<"1\n"<<x[1]<<endl;
    return 0;
}