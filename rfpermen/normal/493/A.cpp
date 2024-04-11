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
#define ff fi.fi
#define fs fi.se
#define sf se.fi
#define ss se.se
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define endl "\n"
const int MAX=2e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);

int n,a[100],b[100];
pair<pair<int,char>, pair<int,char> > x[95];
string s,t;

int main(){
	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s>>t;
    cin>>n;
    rep(i,1,n)cin>>x[i].ff>>x[i].fs>>x[i].sf>>x[i].ss;
    sort(x+1,x+1+n);
    rep(i,1,n){
    	if(x[i].fs=='h'){
    		if(x[i].ss=='y')a[x[i].sf]++;
    		else a[x[i].sf]+=2;
    		if(a[x[i].sf]>=2)cout<<s<<" "<<x[i].sf<<" "<<x[i].ff<<endl, a[x[i].sf]-=1000;
		}
		else {
    		if(x[i].ss=='y')b[x[i].sf]++;
    		else b[x[i].sf]+=2;
    		if(b[x[i].sf]>=2)cout<<t<<" "<<x[i].sf<<" "<<x[i].ff<<endl, b[x[i].sf]-=1000;
		}
	}
    return 0;
}