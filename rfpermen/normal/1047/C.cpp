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
#define ff fi.fi
#define fs fi.se
#define sf se.fi
#define ss se.se
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<pii,int>
#define plll pair<ll,pll>
#define endl "\n"
const ll MAX=3e5+5;
const int MOD=1000000000 + 7;
const ll INF=1e18;
const int nr[]={0,1,0,-1,1,1,-1,-1,  2,2,-2,-2,1,1,-1,-1};
const int nc[]={1,0,-1,0,1,-1,1,-1,  1,-1,1,-1,2,-2,2,-2};

int n,x[MAX],fpb,p[600],k,ans;
bool prima[3875];
map<int,int> m;

int main(){
//    cout<<fixed<<setprecision(9);
    //freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for(int i = 2; i <= 3872; i++){
    	if(prima[i])continue;
    	p[++k] = i;
    	for(int j = i*i; j<=3872; j+=i)prima[j] = 1;
	}
    cin>>n;
    rep(i,1,n)cin>>x[i];
    fpb = __gcd(x[1],x[2]);
    rep(i,3,n)fpb = __gcd(fpb,x[i]);
    rep(i,1,n)x[i]/=fpb;
    rep(i,1,n){
    	if(x[i]==1)continue;
    	rep(j,1,k){
    		if(x[i]%p[j])continue;
    		m[p[j]]++;
    		while(x[i]%p[j]==0)x[i]/=p[j];
		}
		if(x[i]!=1)m[x[i]]++;
	}
	if(m.empty())cout<<-1;
	else {
		ans = n-1;
		for(auto i:m)ans = min(ans,n-i.se);
		cout<<ans;
	}
    return 0;
}