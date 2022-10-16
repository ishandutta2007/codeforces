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
#define piii pair<ll,pll>
#define pdd pair<double,double>
#define endl "\n"
#define usi unsigned short int
const ll MAX=1e6+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=1e18;
const int nr[]={1,-1,0,0,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1};

ll n,x,y;
bool prima[MAX+5];

int main(){
	cout<<fixed<<setprecision(10);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    prima[1] = 1;
    for(int i = 2;i*i<=MAX;i++){
    	if(prima[i])continue;
    	for(int j = i*i;j<=MAX;j+=i)prima[j] = 1;
	}
	cin>>n;
	while(n--){
		cin>>x;
		y = sqrt(x);
		if(y*y==x && !prima[y])cout<<"YES\n";
		else cout<<"NO\n";
	}
    return 0;
}