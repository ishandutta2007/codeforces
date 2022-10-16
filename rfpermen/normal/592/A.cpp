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

int x[9],y[9],a,b;
char c[9][9];

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    rep(i,1,8)rep(j,1,8)cin>>c[i][j];
    a = b = 8;
    rep(j,1,8){
    	x[j] = y[j] = 8;
    	rep(i,1,8){
    		if(c[i][j]=='B')break; 
			else if(c[i][j]=='W'){
	    		x[j] = i-1;
	    		break;
			}
		}
		rap(i,8,1){
			if(c[i][j]=='W')break; 
			else if(c[i][j]=='B'){
	    		y[j] = 8-i;
	    		break;
			}
		}
		a = min(a,x[j]);
		b = min(b,y[j]);
//		cout<<a<<" "<<b<<endl;
	}
	if(a<=b)cout<<'A';
	else cout<<'B';
    return 0;
}