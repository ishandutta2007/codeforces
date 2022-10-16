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
#define w fi
#define sf se.fi
#define ss se.se
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define pdi pair<double,int>
#define endl "\n"
const ll MAX=1e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,-1,0,0,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1};

int n,sz;
string s,x,t,y,com,rem,tmp;
map<string,int> m;
vector<pair<int,string>> ans;

int main(){
	//cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s>>n;
    while(n--){
    	cin>>x>>com;
    	if(com=="likes"){
    		cin>>tmp>>rem;
    		sz = tmp.size()-3;
    		y = "";
    		rep(i,0,sz)y+=tmp[i];
    		if(x!=s && y!=s){
    			m[x]; m[y];
    			continue;
			}
    		m[x]+=5;
    		m[y]+=5;
		}
		else if(com=="posted"){
			cin>>rem>>tmp>>rem;
    		sz = tmp.size()-3;
    		y = "";
    		rep(i,0,sz)y+=tmp[i];
    		if(x!=s && y!=s){
    			m[x]; m[y];
    			continue;
			}
    		m[x]+=15;
    		m[y]+=15;
		}
		else {
			cin>>rem>>tmp>>rem;
    		sz = tmp.size()-3;
    		y = "";
    		rep(i,0,sz)y+=tmp[i];
    		if(x!=s && y!=s){
    			m[x]; m[y];
    			continue;
			}
    		m[x]+=10;
    		m[y]+=10;
		}
	}
	for(auto i:m){
		if(i.fi==s)continue;
		ans.pb({-i.se,i.fi});
		//cout<<i.fi<<endl;
	}
	sort(ans.begin(),ans.end());
	for(auto i:ans)cout<<i.se<<endl;
    return 0;
}