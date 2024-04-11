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
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl;
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 5e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;
 
int tc,n,m,k,le[128],ri[128],pp[128],dd[128];
char c[2005][2005];
bool st;
 
int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>tc;
    while(tc--){
    	rep(i,0,127)le[i] = pp[i] = MOD, ri[i] = dd[i] = 0;
    	st = 1;
    	cin>>n>>m;
    	rep(i,1,n)rep(j,1,m){
    		cin>>c[i][j];
    		if(c[i][j]!='.'){
    			le[c[i][j]] = min(le[c[i][j]],j);
    			ri[c[i][j]] = max(ri[c[i][j]],j);
    			pp[c[i][j]] = min(pp[c[i][j]],i);
    			dd[c[i][j]] = max(dd[c[i][j]],i);
			}
		}
		k = 'a'-1;
		rap(i,'z','a'){
			if(ri[i]==0)continue;
			k = max(k,i);
			if(le[i]!=ri[i]&&pp[i]!=dd[i]){st = 0; break;}
			if(le[i]==ri[i]){
				rep(j,pp[i],dd[i]){
					if(c[j][le[i]]=='.'||c[j][le[i]]<i){st = 0; break;}
				}
			}
			if(pp[i]==dd[i]){
				rep(j,le[i],ri[i]){
//					cout<<c[j][pp[i]]<<endl;
					if(c[pp[i]][j]=='.'||c[pp[i]][j]<i){st = 0; break;}
				}
			}
//			cout<<pp[i]<<' '<<le[i]<<' '<<dd[i]<<' '<<ri[i]<<endl;
		}
		if(st){
			cout<<"YES\n";
			cout<<k-'a'+1<<endl;
			rep(i,'a',k){
				if(ri[i]==0)cout<<pp[k]<<' '<<le[k]<<' '<<dd[k]<<' '<<ri[k]<<endl;
				else cout<<pp[i]<<' '<<le[i]<<' '<<dd[i]<<' '<<ri[i]<<endl;
			}
		}
		else cout<<"NO\n";
	}
	return 0;
}