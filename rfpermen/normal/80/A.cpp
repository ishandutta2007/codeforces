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
const ll MAX=5e3+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=1e18;
const int nr[]={1,-1,0,0,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1};

ll n,m;
bool st;

int main(){
	//cout<<fixed<<setprecision(10);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    if(n==2 && m==3)cout<<"YES";
    else if(n==3 && m==5)cout<<"YES";
    else if(n==5 && m==7)cout<<"YES";
    else if(n==7 && m==11)cout<<"YES";
    else if(n==11 && m==13)cout<<"YES";
    else if(n==13 && m==17)cout<<"YES";
    else if(n==17 && m==19)cout<<"YES";
    else if(n==19 && m==23)cout<<"YES";
    else if(n==23 && m==29)cout<<"YES";
    else if(n==29 && m==31)cout<<"YES";
    else if(n==31 && m==37)cout<<"YES";
    else if(n==37 && m==41)cout<<"YES";
    else if(n==41 && m==43)cout<<"YES";
    else if(n==43 && m==47)cout<<"YES";
    else cout<<"NO";
    return 0;
}