#include <bits/stdc++.h>
 
#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define rap(i,n,N) for(ll i=n;i>=N;--i)
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
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
//#define endl '\n'
const int MAX = 1e3+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

int tc,n,k,lp,id,le,ri,mid,a,b;
bool vis[MAX];
set<int> batu,rem;
vector<int> qu;
string s;

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("input.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    srand(time(NULL));
    cin>>tc;
    while(tc--){
    	cin>>n>>k;
    	memset(vis,0,sizeof vis);
    	batu.clear();
    	lp = min(30,n-1);
    	a = 1, vis[1] = 1, batu.insert(1);
    	rep(i,1,lp){
    		do{
    			b = rand()%n+1;
			}while(vis[b]);
			vis[b] = 1;
			cout<<"? 1 1"<<endl;
			cout<<a<<endl<<b<<endl;
			cin>>s;
			if(s[0]=='S')batu.clear(), batu.insert(b), a = b;
			else if(s[0]=='E')batu.insert(b);
		}
		
		id = 1;
		while(1){
			qu.clear();
			while(id<=n&&qu.size()!=batu.size()){
				if(!batu.count(id))qu.pb(id);
				++id;
			}
			lp = qu.size();
			cout<<"? "<<lp<<' '<<lp<<endl;
			for(auto i:qu)cout<<i<<' '; cout<<endl;
			for(auto i:batu){
				cout<<i<<' ';
				--lp; if(!lp)break;
			}
			cout<<endl;
			cin>>s;
			if(s[0]=='E')for(auto i:qu)batu.insert(i);
			else {
				le = 0, ri = qu.size()-1;
				while(le!=ri){
					mid = le+ri>>1;
					
					lp = mid-le+1;
					cout<<"? "<<lp<<' '<<lp<<endl;
					rep(i,le,mid)cout<<qu[i]<<' '; cout<<endl;
					for(auto i:batu){
						cout<<i<<' ';
						--lp; if(!lp)break;
					}
					cout<<endl;
					
					cin>>s;
					if(s[0]=='E')le = mid+1;
					else ri = mid;
				}
				cout<<"! "<<qu[le]<<endl;
				break;
			}
		}
	}
    return 0;
}