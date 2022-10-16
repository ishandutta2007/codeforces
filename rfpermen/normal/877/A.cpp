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
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define hp se.fi
#define dmg se.se
const ll MAX=100005;
const int MOD=1000000000 + 7;
const ll INF=20000;
const int nr[]={1,-1,0,0,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1};
string x[]={"Danil", "Olya", "Slava", "Ann" , "Nikita"}, s;
int cnt;
int main(){
    cout<<fixed<<setprecision(9);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    rep(i,0,s.size()-1){
    	rep(q,0,4){
    		if(i+x[q].size()>s.size())continue;
    		int st=1;
    		rep(j,0,x[q].size()-1){
    			if(s[i+j]!=x[q][j])st=0;
			}
			cnt+=st;
		}
	}
	if(cnt!=1)cout<<"NO";
	else cout<<"YES";
    return 0;
}