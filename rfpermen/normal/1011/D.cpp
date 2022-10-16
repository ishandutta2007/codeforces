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
#define w fi
#define sf se.fi
#define ss se.se
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define pdi pair<double,int>
//#define endl "\n"
const ll MAX=1e3+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,-1,0,0,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1};

int n,m,le,ri,mid,ans,q,pos;
bool x[35];

int main(){
	//cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>m>>n;
    rep(i,1,n){
    	cout<<1<<endl;
    	cin>>q;
    	if(q==0)return 0;
    	if(q>0)x[i] = 1;
    	else x[i] = 0;
	}
	le = 2, ri = m, pos = 0;
	while(le<=ri){
		pos%=n;
		pos++;
		mid = (le+ri)/2;
		cout<<mid<<endl;
		cin>>q;
		if(q==0)return 0;
		if(x[pos]){
			if(q>0)le=mid+1;
			else ri=mid-1;
		}
		else {
			if(q<0)le=mid+1;
			else ri=mid-1;
		}
	}
	cout<<(le+ri)/2<<endl;
    return 0;
}