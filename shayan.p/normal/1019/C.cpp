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
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxn=1e6+10;
const ll mod=1e9+7;

vector<int>v[maxn],vec;
bool mark[maxn],is[maxn];

int main(){
    int n,m;scanf("%d%d",&n,&m);
    REP(i,m){
	int a,b;scanf("%d%d",&a,&b);
	v[a].PB(b);
    }
    FOR(i,1,n){
	if(!mark[i]){
	    is[i]=1;
	    mark[i]=1;
	    for(ll y:v[i]){
		mark[y]=1;
	    }
	}
    }
    memset(mark,0,sizeof mark);
    FORD(i,n,1){
	if(is[i] && !mark[i]){
	    vec.PB(i);
	    for(ll y:v[i]){
		mark[y]=1;
 	    }
	}
    }
    printf("%d\n",sz(vec));
    for(ll x:vec){
	printf("%d ",x);
    }
}