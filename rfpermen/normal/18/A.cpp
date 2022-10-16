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
#define x first
#define y second
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

ll n,a[3],b,c,d,z,sz,cnt,ans,tx,ty;
string s,t;
pii p[4];
int main(){
	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    rep(i,1,3)cin>>p[i].x>>p[i].y;
    a[0] = (p[1].x-p[2].x)*(p[1].x-p[2].x) + (p[1].y-p[2].y)*(p[1].y-p[2].y);
    a[1] = (p[1].x-p[3].x)*(p[1].x-p[3].x) + (p[1].y-p[3].y)*(p[1].y-p[3].y);
    a[2] = (p[3].x-p[2].x)*(p[3].x-p[2].x) + (p[3].y-p[2].y)*(p[3].y-p[2].y);
    sort(a,a+3);
    if(a[2]==a[0]+a[1] && a[1] && a[2] && a[0])return cout<<"RIGHT",0;
    rep(i,1,3){
    	tx = p[i].x, ty = p[i].y;
    	rep(k,0,3){
    		p[i] = {tx+nr[k], ty+nc[k]};
		    a[0] = (p[1].x-p[2].x)*(p[1].x-p[2].x) + (p[1].y-p[2].y)*(p[1].y-p[2].y);
		    a[1] = (p[1].x-p[3].x)*(p[1].x-p[3].x) + (p[1].y-p[3].y)*(p[1].y-p[3].y);
		    a[2] = (p[3].x-p[2].x)*(p[3].x-p[2].x) + (p[3].y-p[2].y)*(p[3].y-p[2].y);
		    sort(a,a+3);
    		if(a[2]==a[0]+a[1] && a[1] && a[2] && a[0])return cout<<"ALMOST",0;
		}
		p[i] = {tx,ty};
	}
	cout<<"NEITHER";
    return 0;
}