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
typedef pair<int,int> pii;

const ll inf=4e18;
const ll maxn=2e5+10;
const ll mod=1e9+7;

int a[maxn],cn,mn;
vector<int>pos,dl;
bool mark[maxn];

int main(){
    int n;scanf("%d",&n);
    FOR(i,1,n){
	scanf("%d",&a[i]);
	if(a[i]>0){
	    pos.PB(i);
	}
	if(a[i]<0){
	    cn++;
	    if(mn==0 || a[mn]<a[i]){
		mn=i;
	    }
	}
    }
    if(!(cn&1)){
	mn=-1;
    }
    FOR(i,1,n){
	if(a[i]<0 && mn!=i){
	    pos.PB(i);
	}
    }
    if(sz(pos)==0){
	bool yp=0;
	FOR(i,1,n){
	    if(!yp && a[i]==0){
		yp=1;
		continue;
	    }
	    if(yp || i<n)
		dl.PB(i);
	}
    }
    else{
	mark[pos[0]]=1;
	REP(i,sz(pos)-1){
	    printf("1 %d %d\n",pos[i],pos[i+1]);
	    mark[pos[i+1]]=1;
	}
	FOR(i,1,n){
	    if(!mark[i]){
		dl.PB(i);
	    }
	}
    }
    if(sz(dl)){
	REP(i,sz(dl)-1){
	    printf("1 %d %d\n",dl[i],dl[i+1]);
	}
	printf("2 %d\n",dl.back());
    }
}