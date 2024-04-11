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
ll n,cnt;
set<string> se;
string s,t;
bool c[26];
char x;
int main(){
    //cout<<fixed<<setprecision(2);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n){
    	rep(j,0,25)c[j]=0;
    	t="";
    	cin>>s;
    	rep(j,0,s.size()-1)c[s[j]-'a']=1;
    	rep(j,0,25){
    		x=j+'a';
    		if(c[j])t+=x;
    	}
    	se.insert(t);
	}
	cout<<se.size()<<endl;
    return 0;
}