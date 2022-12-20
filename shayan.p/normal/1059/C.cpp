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

const int maxn=1e5+10,mod=1e9+7;
const ll inf=1e18;

void solve(int n,int tw){
    if(n==1){
	printf("%d ",tw);
	return;
    }
    if(n==2){
	printf("%d %d ",tw,2*tw);
	return;
    }
    if(n==3){
	printf("%d %d %d ",tw,tw,3*tw);
	return;
    }
    for(int i=1;i<=n;i+=2){
	printf("%d ",tw);
    }
    solve(n/2,2*tw);
}

int main(){
    int n;scanf("%d",&n);
    solve(n,1);
    printf("\n");
}