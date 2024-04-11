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
#define REP(i,n)  for(int i=0;i<n;i++)
#define REPD(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)

#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pll;

const int inf=1e9;
const int maxn=1e5+10;

#pragma GCC Optimize("Ofast")

int tw;
vector<int>v;

int calc(ll a,ll A,ll b,ll B){// a needs to reach A
	int M=min(int(22),int(sz(v)));
	int ans=inf;
	FORD(mask,(1<<M)-1,0){
		ll copa=a,copb=b;
		int num=0;
		REP(i,M){
			if(bit(mask,i)){
				if(copa<A){
					copa*=v[i];
					num++;
				}
			}
			else{
				if(copb<B){
					copb*=v[i];
					num++;
				}
			}
		}
		int copt=tw;
		while(copt>0&&copa<A){
			copt--;
			copa*=2;
			num++;
		}
		while(copt>0&&copb<B){
			copt--;
			copb*=2;
			num++;
		}
		if(copa>=A&&copb>=B)
			ans=min(ans,num);
	}
	return ans;
}

int main(){
	int a,b,h,w,n;cin>>a>>b>>h>>w>>n;
	REP(i,n){
		int x;cin>>x;
		if(x==2)tw++;
		else v.PB(x);
	}
	sort(v.begin(),v.end(),greater<int>());
	int ans=min(calc(h,a,w,b),calc(h,b,w,a));
	if(ans==inf)cout<<-1;
	else cout<<ans;
	
}