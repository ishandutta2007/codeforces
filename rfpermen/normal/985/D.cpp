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
#define ff fi.fi
#define fs fi.se
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
//#define endl "\n"
const ll MAX=100005;
const int MOD=1000000000 + 7;
const ll INF=1e18;
const int nr[]={1,-1,0,0,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1};
ll n,h,jl,le,ri,mid,ting,sisa,kep,sisa2,tambah,luas,pot;

int main(){
    //cout<<fixed<<setprecision(3);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>h;
    le=1, ri=1500000000;
    while(le<=ri){
    	mid=(le+ri)/2;
    	pot=min(h-1,mid-1);
    	if(mid*mid-pot*(pot+1)/2<=n)luas=mid+mid-min(mid,h) ,ting=mid, le=mid+1;
    	else ri=mid-1;
	}
	pot=min(h-1,ting-1);
	sisa=n-ting*ting+pot*(pot+1)/2;
	//cout<<ting<<" "<<sisa<<endl;
	cout<<luas+(sisa+ting-1)/ting, 0;
    return 0;
}