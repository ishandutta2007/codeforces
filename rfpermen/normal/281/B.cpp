#include <bits/stdc++.h>

#pragma GCC optimize("O3")
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
#define sf se.fi
#define ss se.se
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<piii,pii>
#define endl "\n"
const ll MAX=1e2+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};

int n,le,ri,mid,a1,a2;
double x,y,a,b,mn,eps=1e-9,tmp;

int main(){
	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>x>>y>>n;
    mn = 1e9;
    rep(i,1,n){
    	le = 0, ri = 1e9;
    	b = i;
    	while(le<=ri){
    		mid = (le+ri)/2;
    		a = mid;
    		if(a/b>x/y)ri = mid-1;
    		else tmp = mid, le=mid+1;
		}
		a = tmp;
		if(fabs(a/b - x/y)<mn)mn = fabs(a/b - x/y), a1=tmp, a2=i;
		a = tmp+1;
		if(fabs(a/b - x/y)<mn)mn = fabs(a/b - x/y), a1=tmp+1, a2=i;
		//cout<<mn<<" = "<<a1<<"/"<<a2<<endl;
	}
	cout<<a1<<"/"<<a2<<endl;
    return 0;
}