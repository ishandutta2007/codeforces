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
//#define endl "\n"
#define usi unsigned short int
const ll MAX=1e5+5;
const ll MAX2 = 11;
const ll MOD=1000000000 + 7;
const ll INF=1e18;
const int nr[]={1,-1,0,0,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1};

int x[26],y[26],sz,st,id;
string s,t;

int main(){
	cout<<fixed<<setprecision(0);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s>>t;
    for(auto i:s)x[i-'a']++;
    for(auto i:t)y[i-'a']++;
    rep(i,0,25)if(y[i]>x[i])return cout<<"need tree",0;
    if(s.size()==t.size())return cout<<"array",0;
    sz = s.size()-1;
    st = t.size()-1;
    rep(i,0,st){
    	while(id<=sz && s[id]!=t[i])id++;
    	if(id>sz)return cout<<"both",0;
    	//cout<<id<<endl;
    	id++;
	}
	cout<<"automaton";
    return 0;
}