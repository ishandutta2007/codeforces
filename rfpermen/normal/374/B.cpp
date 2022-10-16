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
const ll MAX=1e2+5;
const ll MAX2 = 11;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,0,-1,0,1,1,-1,-1};
const int nc[]={0,1,0,-1,1,-1,1,-1};

string s;
ll sz,ans,cnt;

int main(){
	cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    sz = s.size()-1;
    ans = 1;
    rep(i,1,sz){
    	if((s[i-1]-'0')+(s[i]-'0')==9)cnt++;
    	else {
    		if(!cnt)continue;
    		if(cnt&1){
    			cnt = 0;
    			continue;
			}
			cnt/=2;
			cnt++;
    		ans*=cnt;
    		cnt = 0;
		}
	}
	if(cnt && !(cnt&1)){
		//cout<<"debug\n";
		cnt/=2;
		cnt++;
		ans*=cnt;
	}
	cout<<ans<<endl;
    return 0;
}