#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
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
//#define ff fi.fi
//#define fs fi.se
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cerr << ">>>>>> " << #x << " -> " << x << endl
#define nani(x) cerr <<  "Line " << __LINE__ << ": " << #x << " is " << x << endl
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

int n,m,a,d,z,atk[MAX],def[MAX],x[MAX],ans,tmp;
bool vis[MAX];
string s;

int main(){
//	cout<<fixed<<setprecision(6);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>m>>n;
    while(m--){
    	cin>>s>>z;
    	if(s[0]=='D')def[++d] = z;
    	else atk[++a] = z;
	}
	rep(i,1,n)cin>>x[i];
	sort(atk+1,atk+1+a);
	sort(def+1,def+1+d);
	sort(x+1,x+1+n);
	//matiin semua kartu lawan
	z = 1;
	rep(i,1,d){
		while(z<=n&&x[z]<=def[i])++z;
		if(z>n){
			z = -1;
			break;
		}
		vis[z] = 1;
		++z;
	}
	if(z!=-1){
		z = 1;
		rep(i,1,a){
			while(z<=n&&(vis[z]||x[z]<atk[i]))++z;
			if(z>n){
				z = -1;
				break;
			}
			ans+=x[z] - atk[i];
			vis[z] = 1;
			++z;
		}
//		db(ans);
//		rep(i,1,n)cout<<vis[i]; cout<<endl;
		if(z!=-1)rep(i,1,n)if(!vis[i])ans+=x[i];
	}
	rep(cb,1,n){
		z = 1, tmp = 0;
		rep(i,cb,n){
			if(z>a)break;
			if(x[i]>=atk[z])tmp+= x[i] - atk[z], z++;
		}
		ans = max(ans,tmp);
	}
	cout<<ans<<endl;
    return 0;
}