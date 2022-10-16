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
#define sf se.fi
#define ss se.se
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);
const double eps = 1e-9;

ll tc,n,k,x[35],y[35],ls;

int main(){
//	cout<<fixed<<setprecision(0);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    x[1] = 1, y[1] = ls = 1;
    rep(i,2,31)x[i] = 1+x[i-1]*4, ls = ls*2+1, y[i] = y[i-1]+ls;
//    rep(i,1,31)cout<<i<<' '<<x[i]<<" "<<y[i]<<endl;
    cin>>tc;
    while(tc--){
    	cin>>n>>k;
    	if(n>31)cout<<"YES "<<n-1<<endl;
    	else if(x[n]<k)cout<<"NO\n";
    	else if(k<=x[n-1]+1)cout<<"YES "<<n-1<<endl;
    	else {
    		if(n==2&&k==3)cout<<"NO\n";
			else if(k>=y[n])cout<<"YES 0\n";
			else cout<<"YES "<<n-2<<endl;
		}
	}
    return 0;
}