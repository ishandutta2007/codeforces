// Can U hack it?

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

const int maxn=(1<<17),CNT=12,MAX=1e5+10;

int a[MAX];
vector< pair<int,pii> >ans;
vector<int>vec;
vector<int> sol[maxn];
int h[maxn];

void Do(vector<int>&vec,int pos){
    for(int x:vec){
	int A=__builtin_ctz(x & -x);
	x-=(1<<A);
	int B=__builtin_ctz(x & -x);
	int C=B+B-A;
	ans.PB({pos-1-C,{pos-1-B,pos-1-A}});
	a[pos-1-C]^=1;
	a[pos-1-B]^=1;
	a[pos-1-A]^=1;
    }
}

void prep(int Size,bool is){
    vec.clear();
    for(int i=0;i<maxn;i++)
	sol[i].clear();
    for(int i=0;i<Size;i++)
	for(int j=i+1;j<Size;j++)
	    for(int k=j+1;k<Size+(is?5:0);k++)
		if(j-i==k-j)
		    vec.PB((1<<i)+(1<<j)+(k>=Size?0:(1<<k)));
    fill(h,h+maxn,1000);
    queue<int>q;
    q.push(0);
    h[0]=0;
    while(sz(q)){
	int u=q.front();
	q.pop();
	for(int x:vec){
	    if(h[u^x]==1000){
		h[u^x]=h[u]+1;
		sol[u^x]=sol[u];
		sol[u^x].PB(x);
		q.push(u^x);
	    }
	}
    }
}

int main(){
    prep(CNT,1);
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
    int pt=n;
    while(pt>17){
	int MSK=0;
	for(int i=0;i<CNT;i++)
	    MSK=2*MSK+a[pt-CNT+i];
	Do(sol[MSK],pt);
	pt-=CNT;
    }
    int last=max(pt,min(n,10));
    prep(last,0);
    int MSK=0;
    for(int i=0;i<last;i++)
	MSK=2*MSK+a[i];
    Do(sol[MSK],last);
    if(h[MSK]==1000){
	printf("NO\n");
	return 0;
    }
    printf("YES\n");
    printf("%d\n",sz(ans));
    for(auto P:ans)
	printf("%d %d %d\n",P.F+1,P.S.F+1,P.S.S+1);
    return 0;
}