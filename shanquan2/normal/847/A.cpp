#include<bits/stdc++.h>
using namespace std;

int l[105],r[105],n,lst;
bool vis[105];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&l[i],&r[i]);
	for(int i=1;i<=n;i++)if(!l[i]){
		int t=i;for(;r[t];t=r[t]);
		if(!lst)lst=t;
		else l[i]=lst,r[lst]=i,lst=t;
	}
	for(int i=1;i<=n;i++)printf("%d %d\n",l[i],r[i]);
	return 0;
}