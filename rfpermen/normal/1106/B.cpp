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
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;

ll n,m,a,b,x[MAX],y[MAX],cnt,sz,tmp,res,id;
pll z[MAX];
string s,t;

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    rep(i,1,n)cin>>x[i];
    rep(i,1,n)cin>>y[i], z[i] = {y[i],i};
    sort(z+1,z+1+n);
    id = 1;
    while(m--){
    	cin>>a>>b;
    	if(x[a]>=b)cout<<y[a]*b<<endl, x[a]-=b;
    	else {
    		tmp = y[a]*x[a], b-=x[a], x[a] = 0;
//    		db(tmp);
    		while(id<=n){
    			if(x[z[id].se]<b)tmp+= y[z[id].se]*x[z[id].se], b-=x[z[id].se], x[z[id].se] = 0, id++;
				else {
					tmp+=y[z[id].se]*b, x[z[id].se]-=b, b = 0;
					break;
				}
			}
//			db(id);
//			db(z[id].se);
			if(b)cout<<"0\n";
			else cout<<tmp<<endl;
		}
	}
    return 0;
}