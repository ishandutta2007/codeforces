#include <bits/stdc++.h>

#pragma GCC optimize("O3")
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
#define piiii pair<piii,pii>
#define endl "\n"
const ll MAX=1e3+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};

int n,d,m,c[13],mx,p,h[600],t;
int main(){
	//cout<<fixed<<setprecision(10);
    freopen("input.txt", "r", stdin);
	freopen("output.txt","w",stdout);
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    c[1] = 200;
    c[2] = 231;
    c[3] = 259;
    c[4] = 290;
    c[5] = 320;
    c[6] = 351;
    c[7] = 381;
    c[8] = 412;
    c[9] = 443;
    c[10]= 473;
    c[11]= 504;
    c[12]= 534;
    cin>>n;
    while(n--){
    	cin>>m>>d>>p>>t;
    	d+=c[m]; d--;
    	rep(i,d-t+1,d)h[i]+=p;
	}
	rep(i,1,550)mx = max(mx,h[i]);
	cout<<mx<<endl;
    return 0;
}