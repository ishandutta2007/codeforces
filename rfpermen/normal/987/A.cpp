#include <bits/stdc++.h>

#pragma GCC optimize("O2")
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
const int MAX=2e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);

int n;
bool vis[6];
string s,ans[] = {"Power","Time","Space","Soul","Reality","Mind"};

int main(){
//	cout<<fixed<<setprecision(12);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n){
    	cin>>s;
    	if(s=="purple")vis[0] = 1;
    	else if(s=="green")vis[1] = 1;
    	else if(s=="blue")vis[2] = 1;
    	else if(s=="orange")vis[3] = 1;
    	else if(s=="red")vis[4] = 1;
    	else if(s=="yellow")vis[5] = 1;
	}
	cout<<6-n<<endl;
	rep(i,0,5)if(!vis[i])cout<<ans[i]<<endl;
    return 0;
}