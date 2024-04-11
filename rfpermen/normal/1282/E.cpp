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
#define ff fi.fi
#define fs fi.se
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e5+5;
const ll MAX2 = 11;
const ll MOD = 998244353;
const ll MOD2 = 1000000006;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 316;

int tc,n,x[MAX][3],y[3],a,b,c,ans[MAX],inv[MAX],id,tmp;
map<int,vector<int>> cnt[MAX];
map<piii,int> hs;
queue<pii> q;
vector<int> ar,v[MAX];
bool st;

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>tc;
    while(tc--){
    	cin>>n;
    	rep(i,1,n)cnt[i].clear(), v[i].clear();
    	hs.clear();
    	rep(i,3,n){
    		ans[i] = 0;
    		rep(j,0,2)cin>>x[i][j];
    		sort(x[i],x[i]+3);
    		a = x[i][0], b = x[i][1], c = x[i][2];
    		hs[{a,{b,c}}] = i;
    		v[a].pb(b), v[a].pb(c);
    		v[b].pb(a), v[b].pb(c);
    		v[c].pb(b), v[c].pb(a);
    		cnt[a][b].pb(c);
    		cnt[a][c].pb(b);
    		cnt[b][c].pb(a);
		}
		ar.clear();
		id = n-2, st = 0;
		rep(i,1,n){
			for(auto j:cnt[i]){
				if(j.se.size()==1){
					b = j.fi, c = j.se[0];
					if(	cnt[min(i,c)][max(i,c)].size()==1 || 
						cnt[min(b,c)][max(b,c)].size()==1){
							ans[hs[{i,{min(b,c),max(b,c)}}]] = id--;
//							cout<<">> "<<i<<' '<<b<<' '<<c<<endl;
							ar.pb(i), ar.pb(b);
							q.push({min(i,c),max(i,c)});
							q.push({min(b,c),max(b,c)});
							st = 1;
							break;
						}
				}
			}
			if(st)break;
		}
//		cout<<ar[0]<<' '<<ar[1]<<endl;
//		for(auto i:v[ar[1]])cout<<i<<' '; cout<<endl;
//		db(cnt[3][6].size());

		rep(i,3,n){
			a = ar[i-2];
			for(auto j:v[a]){
				if(j==ar[i-3])continue;
				b = min(a,j), c = max(a,j);
				if(cnt[b][c].size()==1){
					ar.pb(j);
					break;
				}
			}
		}
		
		for(auto i:ar)cout<<i<<' '; cout<<endl;
		
		while(!q.empty()){
			a = q.front().fi, b = q.front().se; q.pop();
//			cout<<"wkwk "<<a<<' '<<b<<endl;
			for(auto i:cnt[a][b]){
				y[0] = a, y[1] = b, y[2] = i;
				sort(y,y+3);
				tmp = hs[{y[0],{y[1],y[2]}}];
				if(!ans[tmp]){
//					cout<<"<>>< "<<a<<' '<<b<<' '<<c<<endl;
//					db(tmp);
					q.push({y[0],y[1]});
					q.push({y[0],y[2]});
					q.push({y[1],y[2]});
					ans[tmp] = id--;
					break;
				}
			}
		}
		rep(i,3,n)inv[ans[i]+2] = i-2;
		rep(i,3,n)cout<<inv[i]<<' '; cout<<endl;
	}
    return 0;
}