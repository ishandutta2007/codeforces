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
#define pdd pair<double,double> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define endl "\n"
const int MAX=2e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 9;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);

int n,m,x[MAX],pf[MAX],a,b,c;
ll ans;
string s,t;

int main(){
	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s>>t;
    m = s.size(), s = 'a'+s;
    n = t.size(), t = 'a'+t;
    rep(i,1,m)pf[i] = pf[i-1]+(s[i]=='1');
    rep(i,1,n){
    	a = max(1,(i+m)-n), b = min(m,i);
    	c = pf[b]-pf[a-1];
    	if(t[i]=='0')ans+=c;
    	else ans+=(b-a+1)-c;
	}
	cout<<ans<<endl;
    return 0;
}