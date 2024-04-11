#include <bits/stdc++.h>

#pragma GCC optimize("O3")
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
const int MAX = 2e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;

int n,id,sz;
string s[MAX],ans;
vector<bool> op;
bool a,b;//,c

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    id = 1;
    while(cin>>s[id])id++;
    id--;
    if(id!=n+n-1)cout<<"Error occurred\n";
    else {
		rep(i,1,id){
			for(auto j:s[i])ans.pb(j);
			if(s[i][0]=='p'){
				op.pb(0);
				ans.pb('<');
			}
			else {
				op.pb(1);
				while(op.size()>2){
					a = op[op.size()-3], b = op[op.size()-2];//, c = op[op.size()-1]
					if(a==0&&b==1){//&&c==1
						ans.pb('>');
						rep(k,1,3)op.pob();
						op.pb(1);
					}
					else break;
				}
				if(op.size()>1)if(op[op.size()-2]==0)ans.pb(',');
			}
		}
		if(op.size()>1)cout<<"Error occurred\n";
		else cout<<ans<<endl;
	}
	return 0;
}