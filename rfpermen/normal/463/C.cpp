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
const ll MAX=2e3+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};

ll n,a,b,c,x[MAX][MAX],y[2*MAX],z[2*MAX],id1[MAX][MAX],id2[MAX][MAX],tmp,cnt,sz,p,q;
string s,t;
pii a1,a2;

int main(){
	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n)rep(j,1,n)cin>>x[i][j];
    c = 2*n-1;
    a = n, b = 1;
    rep(i,1,c){
    	p = 0;
    	while(a+p<=n && b+p<=n){
    		id1[a+p][b+p] = i;
    		y[i]+=x[a+p][b+p];
    		p++;
		}
		if(a==1)b++;
		else a--;
	}
	a = 1, b = 1;
	rep(i,1,c){
		p = 0;
		while(a-p>0 && b+p<=n){
			id2[a-p][b+p] = i;
			z[i]+=x[a-p][b+p];
			p++;
		}
		if(a==n)b++;
		else a++;
	}
	a = b = 0;
	/*cout<<endl;
	rep(i,1,n){
		rep(j,1,n)cout<<id1[i][j]; cout<<endl;
	}
	cout<<endl;
	rep(i,1,n){
		rep(j,1,n)cout<<id2[i][j]; cout<<endl;
	}*/
	a2 = {1,1}, a1 = {1,2};
	rep(i,1,n)rep(j,1,n){
		tmp = y[id1[i][j]]+z[id2[i][j]]-x[i][j];
		if((i+j)&1){
			if(a<tmp)a = tmp, a1 = {i,j};
		}
		else {
			if(b<tmp)b = tmp, a2 = {i,j};
		}
	}
	cout<<a+b<<endl;
	cout<<a2.fi<<" "<<a2.se<<" "<<a1.fi<<" "<<a1.se<<endl;
    return 0;
}