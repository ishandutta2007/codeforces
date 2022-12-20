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

const int maxn=2e5+10;

bool mark[maxn];
int a[maxn],p[maxn],n;

vector<int>v[maxn];
pii ed[maxn];

queue<int> q;

int main(){
    scanf("%d",&n);
    REP(i,n-1){
	scanf("%d%d",&ed[i].F,&ed[i].S);
    }
    FOR(i,1,n){
	scanf("%d",&a[i]);
	p[a[i]]=i;
    }
    if(a[1]!=1){
	printf("No");
	return 0;
    }
    REP(i,n-1){
	ed[i].F=p[ed[i].F];
	ed[i].S=p[ed[i].S];
	v[ed[i].F].PB(ed[i].S);
	v[ed[i].S].PB(ed[i].F);
    }
    FOR(i,1,n){
	sort(all(v[i]));
    }

    int C=1;
    
    q.push(1);
    mark[1]=1;
    
    while(sz(q)){
	int u=q.front();
	q.pop();
       
	if(C!=u){
	    printf("No");
	    return 0;
	}
	C++;
	
	for(int y:v[u]){
	    if(!mark[y]){
		mark[y]=1;
		q.push(y);
	    }
	}
    }

    printf("Yes");
}