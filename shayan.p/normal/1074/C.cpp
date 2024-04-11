// Phoenix

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=3e5+10,mod=1e9+7,inf=1e9;

pii p[maxn];
vector<int> v;

inline int Dis(int a,int b){
    return abs(p[a].F-p[b].F)+abs(p[a].S-p[b].S);
}

void solve(int &ans,int a,int b,int c){
    if(a==b || a==c || b==c) return;
    ans=max(ans,Dis(a,b)+Dis(b,c)+Dis(c,a));
}

int main(){
    int n;scanf("%d",&n);
    int MX=-inf,mx=inf,my=inf,MY=-inf;
    for(int i=0;i<n;i++){
	scanf("%d%d",&p[i].F,&p[i].S);
	MX=max(MX,p[i].F);
	mx=min(mx,p[i].F);
	my=min(my,p[i].S);
	MY=max(MY,p[i].S);
    }
    for(int i=0;i<n;i++){
	if(p[i].F==MX || p[i].F==mx || p[i].S==my || p[i].S==MY)
	    v.PB(i);
    }
    int ans1=0,ans2=2*(MX-mx+MY-my);
    for(int i=0;i<n;i++)
	for(int id1:v)
	    for(int id2:v)
		solve(ans1,i,id1,id2);
    printf("%d ",ans1);
    for(int i=4;i<=n;i++)
	printf("%d ",ans2);
    printf("\n");
    return 0;
}