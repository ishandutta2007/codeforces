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

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=1e18;
const ll mod=1e9+7;
const ll maxn=2e5+10;

vector<string>v;
ll cnt[20];
string a,b;

string to_str(ll num){
	stringstream stream;stream<<num;
	string s;stream>>s;
	return s;
}

string f(ll num){
	ll tmp[20];
	REP(i,20)
		tmp[i]=cnt[i];
	string s="";
	REP(i,num){
		if(tmp[b[i]-'0']==0)
			return "?";
		tmp[b[i]-'0']--;
		s+=to_str(b[i]-'0');
	}
	if(num==sz(b))
		return s;
	bool yes=0;
	REPD(i,(b[num]-'0')){
		if(tmp[i]>0){
			yes=1;
			tmp[i]--;
			s+=to_str(i);
			break;
		}
	}
	
	if(!yes)
		return "?";
		
	REPD(i,10){
		while(tmp[i]>0){
			tmp[i]--;
			s+=to_str(i);
		}
	}
	return s;
}

int main(){
	cin>>a>>b;
	if(sz(a)<sz(b)){
		sort(a.begin(),a.end(),greater<char>());
		cout<<a;
		return 0;
	}
	// now equal size
	REP(i,sz(a))
		cnt[a[i]-'0']++;
	
	FOR(i,0,sz(a)){
		string s=f(i);
		if(s!="?")
			v.PB(s);
	}
	sort(v.begin(),v.end(),greater<string>());
	cout<<v[0];
}