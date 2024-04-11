#include <bits/stdc++.h>

#pragma GCC optimize("O2")
//#pragma GCC optimize("Ofast,no-stack-protector") 
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native") 
//#pragma GCC optimize("unroll-loops")
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

ll n,mx,tmp;
vector<ll> v;

int main(){
	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    if(n==1)cout<<1;
    else if(n==2)cout<<2;
    else if(n==3)cout<<6;
    else if(n==4)cout<<12;
    else if(n==5)cout<<60;
    else if(n==6)cout<<60;
    else {
    	rep(i,n-3,n)v.pb(i);
    	do{
    		tmp = v[0]*v[1]/__gcd(v[0],v[1]);
    		tmp = tmp*v[2]/__gcd(tmp,v[2]);
    		mx = max(mx,tmp);
		}while(next_permutation(v.begin(),v.end()));
		cout<<mx;
	}
    return 0;
}