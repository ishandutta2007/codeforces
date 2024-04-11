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

const int maxn=5e5+10,mod=1e9+7;
const ll inf=1e18;

ll a[maxn],b[65],ans;
bool mark[maxn];
ll cnt=1;

int main(){
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++){
	ll x;scanf("%lld%lld",&x,&a[i]);
	ans^=x;
	a[i]^=x;
    }
    for(int bt=61;bt>=0;bt--){
	int ind=-1;
	for(int i=0;i<n;i++){
	    if(bit(a[i],bt) && !mark[i])
		ind=i;
	}
	if(ind!=-1){
	    mark[ind]=1;
	    b[bt]=ind+1;
	    for(int i=0;i<n;i++){
		if(bit(a[i],bt) && i!=ind)
		    a[i]^=a[ind];
	    }
	}
    }
    for(int i=0;i<62;i++){
	if(b[i]>0){
	    if(bit(ans,i))
		ans^=a[b[i]-1];
	    cnt*=2;
	}
    }
    if(ans!=0){
	printf("1/1\n");
	return 0;
    }
    printf("%lld/%lld\n",cnt-1,cnt);
}