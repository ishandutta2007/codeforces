#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pii;

#define ff first
#define ss second
#define ep emplace_back
#define eb emplace
#define pb push_back


ll ans;

ll dx[4]={0,1,0,-1};
ll dy[4]={1,0,-1,0};

ll vis[100][100];
ll arr[100][100];
ll chk[100][100];
void dfs(ll x,ll y){
	vis[x][y]=1;
	if(arr[x][y]%2==0) return ;
	if(arr[x][y]==1) ans++;
	for(ll i=0;i<4;i++){
		ll xx=x+dx[i];
		ll yy=y+dy[i];
		if(vis[xx][yy]==0&&arr[xx][yy]%2){
			vis[xx][yy]=1;
			dfs(xx,yy);
		}
	}
}


int main(){
    ll t;
    scanf("%lld",&t);
    while(t--){
    	ans=0;
        ll i,j,k,l,m,n;
        scanf("%lld",&n);
        ll arr[1010]={0,};
        ll brr[1010]={0,};

        pii va[1010]={};
        pii vb[1010]={};

        for(i=1;i<=n;i++)
        	scanf("%lld",&arr[i]);
        for(i=1;i<=n;i++)
        	scanf("%lld",&brr[i]);

        for(i=1;i<=(n+1)/2;i++){
        	pii x;
        	x.ff=min(arr[i],arr[n+1-i]);
        	x.ss=max(arr[i],arr[n+1-i]);
        	if(i==(n+1)/2&&n%2){
        		x.ff=0;
        	}
        	va[i]=x;
        }

        for(i=1;i<=(n+1)/2;i++){
        	pii x;
        	x.ff=min(brr[i],brr[n+1-i]);
        	x.ss=max(brr[i],brr[n+1-i]);
        	if(i==(n+1)/2&&n%2){
        		x.ff=0;
        	}
        	vb[i]=x;
        }

        sort(va+1,va+1+(n+1)/2);
        sort(vb+1,vb+1+(n+1)/2);

        ll chk=1;

        for(i=1;i<=(n+1)/2;i++){
        	if(va[i]!=vb[i]) chk=0;
        }

        if(chk) printf("Yes\n");
        else printf("No\n");
    }
}