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

int n,x[MAX],cnt,k,tmp,z;
ll ans;
unsigned ll y;
map<int,int> m[10];

int main(){
//	cout<<fixed<<setprecision(12);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    rep(i,1,n){
    	cin>>x[i];
    	y = 1;
    	rep(j,0,9)y*=10, m[j][(x[i]*y)%k]++;
	}
    rep(i,1,n){
    	cnt=-1;
    	z = (k - x[i]%k)%k;
    	tmp = x[i];
    	y = 1;
    	while(tmp)cnt++, tmp/=10, y*=10;
    	if(m[cnt].count(z))ans+=m[cnt][z];
    	if((x[i]*y)%k==z)ans--;
	}
	cout<<ans<<endl;
    return 0;
}