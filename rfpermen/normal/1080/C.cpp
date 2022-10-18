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

ll n,m,z,res,tmp,cnt,sz,x,y,tc,w,b,c,d,xx[5];
string s,t;
//map<ll,ll> m;
//char c

int main(){
	cout<<fixed<<setprecision(12);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll x1,x2,x3,x4,y1,y2,y3,y4;
    cin>>tc;
    while(tc--){
    	cin>>n>>m;
    	w = (n*m+1)/2, b = (n*m)/2;
//    	cout<<"awal = "<<w<<' '<<b<<endl;
    	cin>>x1>>y1>>x2>>y2;
    	cin>>x3>>y3>>x4>>y4;
    	
    	x = (x2-x1+1), y = (y2-y1+1);
    	if((x1+y1)&1)w+=(x*y+1)/2, b-=(x*y+1)/2;
		else w+=(x*y)/2, b-=(x*y)/2;
		
    	x = (x4-x3+1), y = (y4-y3+1);
    	if((x3+y3)&1)w-=(x*y)/2, b+=(x*y)/2;
		else w-=(x*y+1)/2, b+=(x*y+1)/2;
		
//		cout<<">> "<<y1<<' '<<y2<<' '<<y3<<' '<<y4<<endl;
		if((x2<x3||x4<x1)||(y2<y3||y4<y1)){
			cout<<w<<' '<<b<<endl;
			continue;
		}
		
		xx[1] = x1,xx[2] = x2,xx[3] = x3,xx[4] = x4;
		sort(xx+1,xx+5);
		x1 = xx[2], x2 = xx[3];
		
		xx[1] = y1,xx[2] = y2,xx[3] = y3,xx[4] = y4;
		sort(xx+1,xx+5);
		y1 = xx[2], y2 = xx[3];
		
		x = (x2-x1+1), y = (y2-y1+1);
    	if((x1+y1)&1)w-=(x*y+1)/2, b+=(x*y+1)/2;
		else w-=(x*y)/2, b+=(x*y)/2;
		
		cout<<w<<' '<<b<<endl;
	}
    return 0;
}