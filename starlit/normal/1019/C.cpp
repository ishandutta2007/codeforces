#include<bits/stdc++.h>
#define N 1000006
#define pb push_back
using namespace std;
int n,m,u,v;
bool del[N];
vector<int>ed[N],ans;
int main(){
	scanf("%d%d",&n,&m);
    for(;m--;)scanf("%d%d",&u,&v),ed[u].pb(v);
    for(int i=1;i<=n;i++)
	if(!del[i])
	for(auto j:ed[i])if(j>i)del[j]=1;
	for(int i=n;i;i--)
	if(!del[i]){
		ans.pb(i);
		for(auto j:ed[i])del[j]=1;
	}
	printf("%d\n",ans.size());
	for(auto i:ans)printf("%d ",i);
}