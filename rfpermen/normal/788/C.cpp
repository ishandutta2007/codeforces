#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
const int MAX = 1e6+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;

int n,k,x[MAX],id,z,sz,bt,a,b,ans;
int vis[MAX];
queue<int> q;

int main(){
//	cout<<fixed<<setprecision(15);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>k>>n;
    rep(i,1,n){
    	cin>>z;
    	if(!vis[z])vis[z] = 1, q.push(z), x[++id] = z;
	}
	sort(x+1,x+1+id);
	if(k>x[id]||k<x[1])return cout<<"-1\n",0;
	if(vis[k])return cout<<"1\n",0;
	ans = 1000;
    rep(i,0,k-1){
    	if(!vis[i])continue;
    	rep(j,k+1,1000){
    		if(!vis[j])continue;
    		a = j - k, b = k - i;
    		if((a+b)/__gcd(a,b)<ans)ans = (a+b)/__gcd(a,b);
		}
	}
	rep(i,1,id)if(x[i]<k)a = i;
	rap(i,id,1)if(x[i]>k)b = i;
	bt = min(x[b]-x[a],50);
	rep(tes,2,bt){
		sz = q.size();
		while(sz--){
			rep(i,1,id){
				z = q.front()+x[i];
				if(vis[z]==tes)continue;
				vis[z] = tes;
				q.push(z);
			}
			q.pop();
		}
		if(vis[k*tes]==tes)return cout<<tes<<endl,0;
	}
	bt = x[b] - x[a];
	while(!q.empty()){
		rep(i,1,id){
			z = q.front();
			rep(tes,51,bt){
				z+=x[i];
				if(z==k*tes){ans = min(ans,tes); break;}
			}
		}
		q.pop();
	}
	cout<<ans<<endl;
	return 0;
}