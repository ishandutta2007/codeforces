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
//#define ff fi.fi
//#define fs fi.se
//#define sf se.fi
//#define ss se.se
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
const int MAX = 2e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll MOD2 = 1000005329;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;

int n,x[MAX],y[MAX],px[MAX],py[MAX],a,b,c,idx,idy,cx,cy;
bool st;
vector<pii> ans;

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n){
    	cin>>c;
    	if(c==1)x[++a] = i, px[i] = a;
    	else y[++b] = i, py[i] = b;
	}
	rep(i,1,200000){
		if(!px[i])px[i] = px[i-1];
		if(!py[i])py[i] = py[i-1];
	}
	rep(jmp,1,n){
		idx = idy = cx = cy = 0;
		while(1){
			if(!x[idx+jmp]&&!y[idy+jmp])break;
			if(!x[idx+jmp]){
				idy+= jmp;
				idx = px[y[idy]];
				++cy;
				st = 1;
			}
			else if(!y[idy+jmp]){
				idx+= jmp;
				idy = py[x[idx]];
				++cx;
				st = 0;
			}
			else if(x[idx+jmp]<y[idy+jmp]){
				idx+= jmp;
				idy = py[x[idx]];
				++cx;
				st = 0;
			}
			else {
				idy+= jmp;
				idx = px[y[idy]];
				++cy;
				st = 1;
			}
			if(x[idx]==n||y[idy]==n){
				if(cx>cy && !st)ans.pb({cx,jmp});
				if(cy>cx &&  st)ans.pb({cy,jmp});
				
				break;
			}
		}
	}
	cout<<ans.size()<<endl;
	sort(all(ans));
	for(auto i:ans)cout<<i.fi<<' '<<i.se<<endl;
    return 0;
}