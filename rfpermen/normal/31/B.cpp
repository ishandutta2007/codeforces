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

string s;
int sz,ls,cnt;

int main(){
	//cout<<fixed<<setprecision(10);
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    sz = s.size()-1;
    if(s[0]=='@' || s[sz]=='@')return cout<<"No solution",0;
    ls = -2;
    rep(i,0,sz){
    	if(s[i]=='@'){
  	    	if(i-ls<3)return cout<<"No solution",0;
  	    	cnt++;
  	    	ls = i;
		}
	}
	if(cnt==0)return cout<<"No solution",0;
	rep(i,0,sz){
		cout<<s[i];
		if(s[i]=='@'){
			cout<<s[i+1];
			i++;
			cnt--;
			if(cnt)cout<<',';
		}
	}
    return 0;
}