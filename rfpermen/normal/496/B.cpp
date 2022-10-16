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
#define endl "\n"
const int MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);

int n,z[1005];
char x[1005],y[2005];
bool st;

int main(){
//	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>x[i], x[i]-='0', z[i]=9;
    rep(k,0,9){
    	rep(i,1,n)y[i] = (x[i]+k)%10;
    	st=0;
    	rep(i,1,n){
	    	if(st)z[i]=y[i];
	    	else if(y[i]<z[i])st=1, z[i] = y[i];
    		else if(y[i]>z[i]&&!st)break;
		}
		rep(j,1,n){
			y[n+j] = y[j];
			st=0;
	    	rep(i,1,n){
	    		if(st)z[i]=y[i+j];
	    		else if(y[i+j]<z[i])st=1, z[i] = y[i+j];
	    		else if(y[i+j]>z[i]&&!st)break;
			}
		}
	}
	rep(i,1,n)cout<<z[i];
    return 0;
}