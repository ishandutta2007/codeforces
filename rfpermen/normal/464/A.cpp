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
const ll MAX=1e3+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};

int n,x,id,upd,nw,ttl;
char s[MAX],mx;
bool st,lim;

bool cek(){
	rep(i,2,n)if(s[i-1]==s[i]){
		s[i]++, upd = i;
		nw = 0;
		rep(j,i+1,n)s[j]=nw+'a', nw = (nw+1)%3;
		return 0;
	}
	rep(i,2,n)if(s[i-1]==s[i+1]){
		s[i+1]++, upd = i+1;
		nw = 0;
		rep(j,i+2,n)s[j]=nw+'a', nw = (nw+1)%3;
		return 0;
	}
	return 1;
}

int main(){
	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>x; mx = 'a'+x-1;
    rep(i,1,n)cin>>s[i];
    s[n]++;
    upd = n;
    while(!st && !lim){
    	id = upd;
    	while(s[id]>mx && id>0)s[id] = 'a', s[--id]++;
    	//rep(i,1,n)cout<<s[i]; cout<<endl;
    	if(!id)lim = 1;
    	else if(cek())st = 1;
	}
	if(lim)cout<<"NO";
	else rep(i,1,n)cout<<s[i];
    return 0;
}