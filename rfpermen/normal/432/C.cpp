#include <bits/stdc++.h>

#pragma GCC optimize("Os")
using namespace std;
#define ll long long
#define rep(i,n,N) for(int i=n;i<=N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);

int n,x[MAX],y[MAX],le,ri,mid,p[MAX],k,cek,res;
vector<pii> ans;
bool prima[MAX+5];

int main(){
//	cout<<fixed<<setprecision(3);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
//    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for(int i = 2; i*i<=MAX; i++){
    	if(prima[i])continue;
    	for(int j = i*i; j<=MAX; j+=i)prima[j] = 1;
	}
	rep(i,2,MAX)if(!prima[i])p[++k] = i;
//	rep(i,1,10)cout<<p[i]<<" "; cout<<endl;
    cin>>n;
    rep(i,1,n)cin>>y[i], x[y[i]] = i;
    rep(i,1,n){
    	while(x[i]!=i){
    		cek = x[i] - i+1;
    		le = 1, ri = k, res = 0;
    		while(le<=ri){
    			mid = (le+ri)/2;
    			if(cek<p[mid])ri = mid-1;
    			else res = x[i]-p[mid]+1, le = mid+1;
			}
//			cout<<i<<" "<<cek<<" "<<x[i]<<" "<<res<<endl;
			x[y[res]] = x[i];
			swap(y[x[i]],y[res]);
			ans.pb({res,x[i]});
			x[i] = res;
		}
	}
	cout<<ans.size()<<endl;
	for(auto i: ans)cout<<i.fi<<" "<<i.se<<endl;
    return 0;
}