#include<bits/stdc++.h>
#define PB push_back
#define PF push_front
#define POF pop_front
#define POB pop_back
#define sz(s) (s.size())
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define FORD(i,a,b) for(ll i=a;i>=b;i--)
#define REP(i,a) for(ll i=0;i<a;i++)
#define REPD(i,a) for(ll i=a-1;i>=0;i--)
#define MP make_pair
#define F first
#define S second

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=1e18;
const ll maxn=2e5+10;

vector<pair<char,ll> >v[2];
int main(){
	string s;cin>>s;
	s=s+".";
	char ch=s[0];
	ll num=1,Min=inf;
	FOR(i,1,sz(s)-1){
		if(ch!=s[i]){
			ll t=((v[0].empty()||i==sz(s)-1)?num:((num/2)+(num%2)));
			Min=min(Min,t);
			v[0].PB(MP(ch,num));
			ch=s[i];
			num=0;
		}
		num++;
	}
	ll o=0,O=1;
	ll time=0;
	while(sz(v[o])>1){
		time+=Min;
		v[O].clear();
		REP(i,sz(v[o])){
			ll num=v[o][i].S;
			ll kam=((i==0||i==sz(v[o])-1)?(num-Min):(max(ll(0),num-2*Min)));
			if(kam==0)continue;
			v[O].PB(MP(v[o][i].F,kam));
			while(sz(v[O])>1&&v[O][sz(v[O])-1].F==v[O][sz(v[O])-2].F){
				v[O][sz(v[O])-2].S+=v[O][sz(v[O])-1].S;
				v[O].POB();
			}
		}
		Min=inf;
		REP(i,sz(v[O])){
			ll num=v[O][i].S;
			ll t=((i==0||i==sz(v[O])-1)?num:((num/2)+(num%2)));
			Min=min(Min,t);
		}
		o++;
		O++;
		o%=2;
		O%=2;
	}
	cout<<time;
}