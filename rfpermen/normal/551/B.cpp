#include <bits/stdc++.h>

#pragma GCC optimize("O2")
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
const int MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};

int x[26],y[26],z[26],mx,c,p,q;
string s,a,b;
bool st;

int main(){
//	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s; for(auto i:s)x[i-'a']++;
    cin>>a; for(auto i:a)y[i-'a']++;
    cin>>b; for(auto i:b)z[i-'a']++;
    c = 1e6;
    rep(i,0,25)if(y[i])c = min(c,x[i]/y[i]);
    rep(i,0,25)x[i]-=y[i]*c;
    mx = c;
    p = c;
    rep(k,1,100000){
    	st = 1;
    	rep(i,0,25)if(z[i]*k>x[i])st=0;
    	while(!st&&c){
    		c--;
    		rep(i,0,25)x[i]+=y[i];
    		st=1;
    		rep(i,0,25)if(z[i]*k>x[i])st=0;
		}
		if(!st)break;
		if(mx<k+c)mx = k+c, p = c, q = k;
	}
	memset(x,0,sizeof x);
	for(auto i:s)x[i-'a']++;
	rep(i,0,25)x[i]-=p*y[i]+q*z[i];
	while(p--)cout<<a;
	while(q--)cout<<b;
	rep(i,0,25)while(x[i]--)cout<<(char)(i+'a');
    return 0;
}