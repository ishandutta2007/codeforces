#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<ll> v[101010];
ll chk[101010];
ll go[101010];
int main()
{
   	ll t;
   	scanf("%lld",&t);
   	while(t--){
   		ll n,m,i,j,k,l;
   		scanf("%lld",&n);
   		for(i=1;i<=n;i++){
   			scanf("%lld",&m);
   			while(m--){
   				scanf("%lld",&k);
   				v[i].push_back(k);
   			}
   		}
   		for(i=1;i<=n;i++){
   			for(auto x:v[i]){
   				if(chk[x]==0){
   					chk[x]=1;
   					go[i]=1;
   					break;
   				}
   			}
   		}
   		ll cchk=1;
   		for(i=1;i<=n;i++){
   			if(go[i]==0){
   				for(j=1;j<=n;j++){
   					if(chk[j]==0){
   						break;
   					}
   				}
   				printf("IMPROVE\n");
   				printf("%lld %lld\n",i,j);
   				cchk=0;
   				break;
   			}
   		}
   		if(cchk) printf("OPTIMAL\n");
   		for(i=1;i<=n;i++){
   			go[i]=chk[i]=0;
   			v[i].clear();
   		}
   	}
}