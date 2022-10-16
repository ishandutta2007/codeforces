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
const ll MAX=1e6+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};

int a,b,k,le,ri,cek,mid,ans,p[MAX];


int main(){
//	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    rap(i,MAX-1,2)p[i] = 1;
    for(int i = 2; i*i<MAX; i++){
    	if(!p[i])continue;
    	for(int j = i*i; j<MAX; j+=i)p[j] = 0;
	}
	rep(i,1,1000000)p[i]+=p[i-1];
	cin>>a>>b>>k;
	le = 1, ri = b-a+1, ans = -1;
	while(le<=ri){
		mid = (le+ri)/2;
		cek = p[b] - p[b-mid];
		rap(i,b-mid,a)cek = min(cek,p[i+mid-1]-p[i-1]);
//		cout<<mid<<" "<<cek<<endl;
		if(cek>=k)ans = mid, ri = mid-1;
		else le = mid+1;
	}
	cout<<ans<<endl;
    return 0;
}