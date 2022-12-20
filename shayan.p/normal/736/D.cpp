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

const int maxn=2010,maxm=5e5+10;

bitset<maxn>a[maxn],b[maxn];
int n,m;
pii p[maxm];

int main(){
    int n,m;scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
	scanf("%d%d",&p[i].F,&p[i].S);
	a[--p[i].F][--p[i].S]=1;
    }
    for(int i=0;i<n;i++){
	b[i][i]=1;
    }
    for(int i=0;i<n;i++){
	int fnd=-1;
	for(int j=i;j<n;j++){
	    if(a[j][i])fnd=j;
	}
	swap(a[i],a[fnd]);
	swap(b[i],b[fnd]);
	for(int j=0;j<n;j++){
	    if(i!=j && a[j][i]){
		a[j]^=a[i];
		b[j]^=b[i];
	    }
	}
    }
    for(int i=0;i<m;i++){
	if(b[p[i].S][p[i].F])printf("NO\n");
	else printf("YES\n");
    }
}