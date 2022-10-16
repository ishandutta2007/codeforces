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
const int MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);

int n,x[MAX],le,ans,mn,mx,a,b,c,d;

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>x[i];
    le = ans = a = b = c = d = 1;
    mn = mx = x[1];
    rep(i,2,n){
    	if(x[i]<=mn){
    		if(x[i]==mn)a = i;
    		else {
    			ans = max(ans,i-le);
				if(mn-x[i]==1){
					if(mx!=mn)mx = mn, d = le = b+1, b = a;
					mn = x[i], a = c = i;
				}
    			else mx = mn = x[i], a = b = c = d = le = i;
			}
		}
		if(x[i]>=mx){
    		if(x[i]==mx)b = i;
    		else {
    			ans = max(ans,i-le);
    			if(x[i]-mx==1){
    				if(mn!=mx)mn = mx, c = le = a+1, a = b;
					mx = x[i], b = d = i;
				}
    			else mx = mn = x[i], a = b = c = d = le = i;
			}
		}
//		cout<<mn<<" "<<c<<" "<<a<<" - "<<mx<<" "<<d<<" "<<b<<" , "<<le<<" "<<i<<endl;
	}
//	cout<<le<<endl;
	cout<<max(ans,n-le+1);
    return 0;
}