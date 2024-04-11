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
        scanf("%lld %lld",&n,&m);
        string s;
        ll cnt1=0;
        ll cnt2=0;
        for(i=1;i<=n;i++){
        	cin>>s;
        	for(j=0;j<m;j++){
        		if(s[j]=='G'){
        			cnt1++;
        			arr[i][j+1]=1;
         		}
         		if(s[j]=='#') arr[i][j+1]=2;
         		if(s[j]=='.') arr[i][j+1]=3;
        	}   
        }

        for(i=1;i<=n;i++){
        	for(j=1;j<=m;j++){
        		if(arr[i][j]==0){
        			chk[i-1][j]=chk[i+1][j]=chk[i][j+1]=chk[i][j-1]=2;
        		}
        	}
        }

         for(i=1;i<=n;i++){
        	for(j=1;j<=m;j++){
        		if(chk[i][j]){
        			arr[i][j]=2;
        		}
        	}
        }

        dfs(n,m);
        for(i=0;i<=n+1;i++)
        	for(j=0;j<=m+1;j++)
        		chk[i][j]=arr[i][j]=vis[i][j]=0;

        if(ans==cnt1) printf("Yes\n");
        else printf("No\n");
    }
}