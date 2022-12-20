// new day,new strength,new thougts
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) int((c).size())
#define REP(i,n)  for(int i=0;i<int(n);i++)
#define REPD(i,n) for(int i=int(n)-1;i>=0;i--)
#define FOR(i,a,b) for(int i=int(a);i<=int(b);i++)
#define FORD(i,a,b) for(int i=int(a);i>=int(b);i--)
#define FORK(i,a,b,c) for(int i=int(a);i<=b;i+=c)
#define all(s) (s).begin(),(s).end()
#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

const ll inf=4e18;
const ll maxn=1e6+10;
const ll mod=1e9+7;

map<int,int>mp;
vector<int>v;

int main(){
    int t;scanf("%d",&t);
    while(t--){
	int n;scanf("%d",&n);
	mp.clear();
	v.clear();
	REP(i,n){
	    int x;scanf("%d",&x);
	    mp[x]++;
	}
	double ans=200000000;
	pii pind={-1,-1};
	for(pii p:mp){
	    if(p.S<2)continue;
	    if(p.S>=4)ans=2,pind={p.F,p.F};
	    v.PB(p.F);
	}
	REP(i,sz(v)){
	    int l=i+1,r=sz(v)-1;
	    while(l<r){
		int mid=(l+r)/2;
		ld num1=(double(v[i])/v[mid])+(double(v[mid])/v[i]),num2=(double(v[i])/v[mid+1])+(double(v[mid+1])/v[i]);
		if(num1>num2){
		    l=mid+1;
		}
		else{
		    r=mid;
		}
	    }
	    if(l==r && ans> ((double(v[l])/v[i])+(double(v[i])/v[l]))){
		ans=(double(v[l])/v[i])+(double(v[i])/v[l]);
		pind={v[i],v[l]};
	    }
	}
	printf("%d %d %d %d\n",pind.F,pind.F,pind.S,pind.S);
    }
}