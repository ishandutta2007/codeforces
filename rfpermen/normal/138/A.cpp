#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(ll i=n;i<=N;++i)
#define rap(i,n,N) for(ll i=n;i>=N;--i)
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
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>>>> " << #x << " -> " << x << endl;
#define all(x) x.begin(),x.end()
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define plll pair<ll,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl "\n"
const int MAX = 1e5+5;
const ll MAX2 = 11;
const ll MOD = 1000000007;
const ll INF = 1e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 450;

int n,k,det,x;
string s[4],t;

int main(){
//	cout<<fixed<<setprecision(15);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    while(n--){
    	rep(i,0,3){
    		cin>>s[i];
    		reverse(all(s[i]));
    		t = "", x = k;
    		for(auto j:s[i]){
    			if(j=='a'||j=='i'||j=='u'||j=='e'||j=='o')--x;
				t.pb(j);
    			if(!x)break;
			}
    		if(x)return cout<<"NO\n",0;
    		s[i] = t;
		}
		if(s[0]==s[1]&&s[1]==s[2]&&s[2]==s[3])continue;
		if(det==1){
			if(s[0]!=s[1]||s[2]!=s[3])return cout<<"NO\n",0;
		}
		else if(det==2){
			if(s[0]!=s[2]||s[1]!=s[3])return cout<<"NO\n",0;
		}
		else if(det==3){
			if(s[0]!=s[3]||s[2]!=s[1])return cout<<"NO\n",0;
		}
		else {
			if(s[0]==s[1]&&s[2]==s[3])det = 1;
			else if(s[0]==s[2]&&s[1]==s[3])det = 2;
			else if(s[0]==s[3]&&s[2]==s[1])det = 3;
			else return cout<<"NO\n",0;
		}
	}
	if(det==1)cout<<"aabb";
	else if(det==2)cout<<"abab";
	else if(det==3)cout<<"abba";
	else cout<<"aaaa";
	return 0;
}