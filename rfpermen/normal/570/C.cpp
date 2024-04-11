#include <bits/stdc++.h>

#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define rep(i,n,N) for(ll i=n;i<=N;i++)
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
const int MAX=3e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);

int n,m,cnt,k;
char c[MAX],x;

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    rep(i,1,n)cin>>c[i];
    rep(i,1,n){
    	if(c[i]=='.')k++;
    	else if(k)cnt+=k-1, k=0;
	}
	if(k)cnt+=k-1;
    while(m--){
    	cin>>k>>x;
    	if(x=='.'){
    		if(c[k]=='.'){
    			cout<<cnt<<endl;
    			continue;
			}
			if(c[k-1]=='.'&&c[k+1]=='.')cnt+=2;
			else if(c[k-1]=='.'||c[k+1]=='.')cnt++;
			cout<<cnt<<endl;
		}
		else {
    		if(c[k]!='.'){
    			cout<<cnt<<endl;
    			continue;
			}
			if(c[k-1]=='.'&&c[k+1]=='.')cnt-=2;
			else if(c[k-1]=='.'||c[k+1]=='.')cnt--;
			cout<<cnt<<endl;
		}
		c[k] = x;
	}
    return 0;
}