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
const ll MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};

ll n,a,b,c,d,x[234],y[234],z,sz,T,nw,l,r;
string s,t;

int main(){
	//cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>x[i]>>y[i];
    rep(i,1,n){
    	a = b = c = d = 0;
    	rep(j,1,n){
    		if(x[i]==x[j]){
    			if(y[i]<y[j])a++;
    			else if(y[i]>y[j])b++;
			}
			else if(y[i]==y[j]){
				if(x[i]<x[j])c++;
				else if(x[i]>x[j])d++;
			}
		}
		if(a&&b&&c&&d)z++;
	}
	cout<<z;
    return 0;
}