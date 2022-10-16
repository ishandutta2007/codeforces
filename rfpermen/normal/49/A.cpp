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
const ll MAX=1e3+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};

ll n,a,b,c,x,y,z,sz,cnt,ans,tmp;
string s,t;

int main(){
	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    getline(cin,s);
    for(auto i:s){
    	if(i>='a' && i<='z')t+=i;
    	else if(i>='A' && i<='Z')t+=(i-'A'+'a');
	}
	if(t.size()==0)cout<<"NO";
	else if(t[t.size()-1]=='a' || t[t.size()-1]=='i' || t[t.size()-1]=='u' || t[t.size()-1]=='e' || t[t.size()-1]=='o' || t[t.size()-1]=='y')cout<<"YES";
	else cout<<"NO";
    return 0;
}