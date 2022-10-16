#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
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
const int MAX = 3e2+5;
const ll MAX2 = 11;
const ll MOD = 998244353;
const ll MOD2 = 1000000006;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 316;

int n,ttl,nw,ans,pos,jk,x[MAX][MAX],mx[MAX][MAX],hit;
bool st[MAX][MAX];
string s[MAX];

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>s[i], ttl+= s[i].size();
    ttl+= n-1;
    rep(i,1,n)rep(j,i+1,n)if(s[i].size()==s[j].size() && s[i]==s[j])st[i][j] = 1;
    rep(i,1,n){
    	jk = n-i;
    	x[i][0] = s[i].size()-1;
    	rep(k,1,jk)x[i][k] = x[i][k-1] + s[i+k].size();
	}
    rep(i,1,n)rep(j,i+1,n){
    	jk = j-i-1;
    	hit = -1;
    	rep(k,0,jk){
    		if(!st[i+k][j+k])break;
    		++hit;
		}
		mx[i][j] = hit;
	}
	rep(i,1,n){
		jk = n-i;
		rep(k,0,jk){
			nw = 0, pos = i+k+1;
			while(pos+k<=n){
				if(mx[i][pos]<k)++pos;
				else {
					if(!nw)nw = x[i][k]<<1;
					else nw+= x[i][k];
					pos+= k+1;
				}
			}
			ans = max(ans,nw);
		}
	}
	cout<<ttl-ans<<endl;
    return 0;
}