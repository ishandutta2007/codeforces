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
#define all(n) n.begin(),n.end()
#define fi first
#define se second
#define sf se.fi
#define ss se.se
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX=3e5+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int dr[]={1,0,-1,0,1,1,-1,-1};
const int dc[]={0,1,0,-1,1,-1,1,-1};
const double pi = acos(-1);
const double eps = 1e-9;

ll n,x,y,z,sz,cnt,tmp,res,a,b,c,k,m;
bool v[MAX];
string s,t;
//set<int> s;

int main(){
//	cout<<fixed<<setprecision(12);
//    freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s>>s;
    sz = s.size()-1;
    if(sz<2)return cout<<s,0;
    rep(i,2,sz){
    	if(s[i-2]=='o'&&s[i-1]=='g'&&s[i]=='o'){
    		s[i-2]='*',s[i-1]='*',s[i]='*';
    		cout<<"***";
    		while(i<=sz){
    			i+=2;
    			if(s[i-1]=='g'&&s[i]=='o')s[i-1]='*',s[i]='*';
    			else break;
			}
		}
		else cout<<s[i-2];
	}
	if(s[sz-1]!='*')cout<<s[sz-1];
	if(s[sz]!='*')cout<<s[sz];
    return 0;
}