// Believe in yourself...
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) (c).size()
#define REP(i,n)  for(ll i=0;i<n;i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define FORD(i,a,b) for(ll i=a;i>=b;i--)

#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll mod=1e9+7;
const ll maxn=2e5+10;

#pragma GCC Optimize("Ofast")

ll cnt[12];

string solve(string &s){
	memset(cnt,0,sizeof cnt);
	pll yes=MP(-1,-1);
	REP(i,(sz(s)))
		cnt[s[i]-'0']++;
	REPD(i,sz(s)){
		cnt[s[i]-'0']--;
		REPD(j,(s[i]-'0')){// 0 -1 bug
			if(i==0&&j==0)// no leading zeros
				continue;
			cnt[j]++;
			ll num=0;
			REP(k,10)
				num+=(cnt[k]%2);
			if(num<=(sz(s)-i-1)){
				yes=MP(i,j);
				break;
			}
			cnt[j]--;
		}
		if(yes.F!=-1)
			break;
	}
	string ans="";
	if(yes.F==-1){
		REP(i,(sz(s)-2))
			ans+="9";
	}
	else{
		vector<ll>v;v.clear();
		REP(k,10){
			if(cnt[k]%2)
				v.PB(k);
		}
		s[yes.F]=char(yes.S+'0');
		ans=s.substr(0,yes.F+1);
		REP(i,(sz(s)-yes.F-1))
			ans+="9";
		REP(i,sz(v))
			ans[sz(ans)-i-1]=char(v[i]+'0');
	}
	return ans;
}

int main(){
	ll t;cin>>t;
	while(t--){
		string s;cin>>s;
		cout<<solve(s)<<endl;
	}
}