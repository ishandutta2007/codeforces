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
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
const ll MAX=100010;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,-1,0,0,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1};
ll n,q,x,y,z,tot,pre[200005],le,ri,mid,cor;
int main(){
    //cout<<fixed<<setprecision(2);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>q;
    rep(i,1,n){
    	cin>>x;
    	tot+=x;
    	pre[i]=x+pre[i-1];
	}
	//rep(i,1,n)cout<<pre[i]<<" ";cout<<endl;
	while(q--){
		cin>>y;
		z+=y;
		if(z>=tot){
			z=0;
			cout<<n<<endl;
			continue;
		}
		le=0,ri=n;
		while(le<=ri){
			mid=(le+ri)/2;
			if(pre[mid]>z)ri=mid-1;
			else le=mid+1,cor=mid;
		}
		//cout<<" sd "<<z<<endl;
		cout<<n-cor<<endl;
	}
    return 0;
}