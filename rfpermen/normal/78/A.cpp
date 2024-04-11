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
const int MAX=1e8;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};

int x;
string s;

int main(){
	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    getline(cin,s); x=0;
    for(auto i:s){
    	if(i=='a' || i=='i' || i=='u' || i=='e' || i=='o')x++;
	}
	if(x!=5)return cout<<"NO",0;
    getline(cin,s); x=0;
    for(auto i:s){
    	if(i=='a' || i=='i' || i=='u' || i=='e' || i=='o')x++;
	}
	if(x!=7)return cout<<"NO",0;
    getline(cin,s); x=0;
    for(auto i:s){
    	if(i=='a' || i=='i' || i=='u' || i=='e' || i=='o')x++;
	}
	if(x!=5)return cout<<"NO",0;
	cout<<"YES";
    return 0;
}