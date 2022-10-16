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
const int MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);

int n;
char c;
bool x[10],a,b,z,y;

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    while(n--){
    	cin>>c;
    	x[c-'0']=1;
	}
	x[8]=0;
	if(x[0]&&(x[1]||x[2]||x[3]))return cout<<"YES",0;
	rep(i,1,3)if(x[i])a=1;
	rep(i,7,9)if(x[i])b=1;
	for(int i=1;i<10;i+=3)if(x[i])y=1;
	for(int i=3;i<10;i+=3)if(x[i])z=1;
	if(a&&b&&z&&y)cout<<"YES";
	else cout<<"NO";
    return 0;
}