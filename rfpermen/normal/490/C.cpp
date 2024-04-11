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
const ll MAX=1e6+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};

int a,b,x[MAX],y[MAX],sz,m;
bool z[MAX];
string s;

int main(){
	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s>>a>>b;
    sz = s.size();
    s = 'a'+s;
    rep(i,1,sz){
    	x[i] = (x[i-1]*10 + s[i]-'0')%a;
	}
	m = 1;
	rap(i,sz,1){
		if(s[i]=='0')z[i] = 0;
		else z[i] = 1;
		y[i] = ((s[i]-'0')*m + y[i+1])%b;
		m = (m*10)%b;
	}
	rep(i,1,sz){
		//cout<<i<<" "<<x[i]<<" "<<y[i+1]<<endl;
		if(!x[i] && !y[i+1] && z[i+1]){
			cout<<"YES\n";
			rep(j,1,i)cout<<s[j]; cout<<endl;
			rep(j,i+1,sz)cout<<s[j];
			return 0;
		}
	}
	cout<<"NO";
    return 0;
}