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

int n,a,b,c1,c2,df;
pii x[MAX];
stack<int> a1,a2;

int main(){
	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)cin>>x[i].fi, x[i].se = i;
    sort(x+1,x+1+n);
    reverse(x+1,x+1+n);
    a = x[1].fi;
    c1 = 1;
    a1.push(x[1].se);
    rep(i,2,n){
    	if((a>b && c1>=c2) || c1>c2)c2++, b+=x[i].fi, a2.push(x[i].se);
		else c1++, a+=x[i].fi, a1.push(x[i].se);
	}
	cout<<c1<<endl;
	while(!a1.empty())cout<<a1.top()<<" ", a1.pop(); cout<<endl;
	cout<<c2<<endl;
	while(!a2.empty())cout<<a2.top()<<" ", a2.pop(); cout<<endl;
    return 0;
}