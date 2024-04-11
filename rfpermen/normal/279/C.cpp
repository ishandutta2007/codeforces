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

int n,m,l,r,k,x[MAX],y[MAX],nw,id;
bool st;

int main(){
	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    rep(i,1,n)cin>>x[i];
    nw=1, st=1; y[1] = 1;
    rep(i,2,n){
    	if(x[i]>x[i-1]){
    		if(st)y[i] = -nw;
    		else {
    			nw++;
    			id=i-1;
    			while(id>0 && x[id]==x[i-1])y[id] = nw, id--;
    			y[i] = -nw, st = 1;
			}
		}
		else if(x[i]==x[i-1])y[i] = -nw;
		else if(x[i]<x[i-1]){
			y[i] = -nw;
			if(st)st = 0;
		}
	}
	//rep(i,1,n)cout<<y[i]<<" "; cout<<endl;
    while(m--){
    	cin>>l>>r;
    	//cout<<y[l]<<" "<<y[r]<<endl;
    	if(y[l]<0 && y[r]<0){
    		if(y[l]==y[r])cout<<"Yes\n";
    		else cout<<"No\n";
		}
		else if(y[r]>0 && abs(y[r])-abs(y[l])<2)cout<<"Yes\n";
		else if(abs(y[r])-abs(y[l]))cout<<"No\n";
		else cout<<"Yes\n";
	}
    return 0;
}