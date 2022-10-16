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
//#define endl "\n"
const ll MAX=1e3+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};

ll n,a,b,c,x,y,z,sz,cnt,tmp,ans,le,ri;
string s,t;
char rem;
int main(){
	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    le = -2e9, ri = 2e9;
    while(n--){
    	if(le>ri)return cout<<"Impossible",0;
    	cin>>s>>x>>rem;
    	if(s==">="){
    		if(rem=='N')ri = min(ri,x-1);
    		else le = max(x,le);
		}
		else if(s==">"){
    		if(rem=='N')ri = min(ri,x);
    		else le = max(x+1,le);
		}
		else if(s=="<="){
			if(rem=='N')le = max(x+1,le);
    		else ri = min(ri,x);
		}
		else {
			if(rem=='N')le = max(x,le);
    		else ri = min(ri,x-1);
		}
		//cout<<le<<" "<<ri<<" "<<x<<endl;
	}
	if(le>ri)cout<<"Impossible";
	else cout<<(le+ri)/2;
    return 0;
}