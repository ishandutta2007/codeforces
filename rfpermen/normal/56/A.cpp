#include <bits/stdc++.h>

#pragma GCC optimize("O3")
using namespace std;
#define ll long long
#define rep(i,n,N) for(ll i=n;i<=N;i++)
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

ll n,a,b,c,x,y,z,sz,cnt,ans,tmp;
string s,t;

int main(){
	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    while(n--){
    	cin>>s;
    	if(s=="ABSINTH")cnt++;
    	else if(s=="BEER")cnt++;
    	else if(s=="BRANDY")cnt++;
    	else if(s=="CHAMPAGNE")cnt++;
    	else if(s=="GIN")cnt++;
    	else if(s=="RUM")cnt++;
    	else if(s=="SAKE")cnt++;
    	else if(s=="TEQUILA")cnt++;
    	else if(s=="VODKA")cnt++;
    	else if(s=="WHISKEY")cnt++;
    	else if(s=="WINE")cnt++;
    	else {
    		if(s.size()==1 && s[0]>='0' && s[0]<='9')cnt++;
    		if(s.size()==2){
    			if(s[0]=='1' && s[1]<='7')cnt++;
			}
		}
	}
	cout<<cnt;
    return 0;
}