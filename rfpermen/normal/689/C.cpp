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

ll n,le,ri,mid,ans,cek;

int main(){
//	cout<<fixed<<setprecision(10);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    le = 1, ri = 1000000000000000000, ans = -1;
    while(le<=ri){
    	mid = (le+ri)/2;
    	cek = 0;
    	rep(i,2,1000000){
    		if(mid/i/i/i==0)break;
    		cek+=mid/i/i/i;
		}
    	if(cek>n)ri = mid-1;
    	else if(cek<n)le = mid+1;
    	else ri = mid-1, ans = mid;
	}
	cout<<ans<<endl;
    return 0;
}