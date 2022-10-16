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
const ll MAX=1e2+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};

int n,m,a[MAX],b[MAX],d[MAX],mx,sz;
string s[MAX];
char c[6];
vector<string> ans;

int main(){
	cout<<fixed<<setprecision(0);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n){
    	cin>>m>>s[i];
    	while(m--){
    		cin>>c[0]>>c[1]>>c[5]>>c[2]>>c[3]>>c[5]>>c[4]>>c[5];
    		if(c[0]==c[1] && c[1]==c[2] && c[2]==c[3] && c[3]==c[4] && c[4]==c[5])a[i]++;
    		else if(c[0]>c[1] && c[1]>c[2] && c[2]>c[3] && c[3]>c[4] && c[4]>c[5])b[i]++;
    		else d[i]++;
		}
	}
	mx = 0;
	ans.clear();
	rep(i,1,n)mx = max(mx,a[i]);
	rep(i,1,n)if(a[i]==mx)ans.pb(s[i]);
	sz = ans.size()-1;
	cout<<"If you want to call a taxi, you should call: "<<ans[0];
	rep(i,1,sz)cout<<", "<<ans[i]; cout<<".\n";
	mx = 0;
	ans.clear();
	rep(i,1,n)mx = max(mx,b[i]);
	rep(i,1,n)if(b[i]==mx)ans.pb(s[i]);
	sz = ans.size()-1;
	cout<<"If you want to order a pizza, you should call: "<<ans[0];
	rep(i,1,sz)cout<<", "<<ans[i]; cout<<".\n";
	mx = 0;
	ans.clear();
	rep(i,1,n)mx = max(mx,d[i]);
	rep(i,1,n)if(d[i]==mx)ans.pb(s[i]);
	sz = ans.size()-1;
	cout<<"If you want to go to a cafe with a wonderful girl, you should call: "<<ans[0];
	rep(i,1,sz)cout<<", "<<ans[i]; cout<<".\n";
    return 0;
}