#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,res,sb[200500];

int main(){
	scanf("%d%d",&n,&m);
	res=n;
	for(i=1;i<=m;i++){
		scanf("%d%d",&j,&k);
		if(j>k){swap(j,k);}
		sb[j]++;
		if(sb[j]==1){res--;}
	}
	scanf("%d",&t);
	while(t--){
		scanf("%d",&k);
		if(k==1){
			scanf("%d%d",&i,&j);
			i=min(i,j);
			sb[i]++;
			if(sb[i]==1){res--;}
			continue;
		}
		if(k==2){
			scanf("%d%d",&i,&j);
			i=min(i,j);
			sb[i]--;
			if(sb[i]==0){res++;}
			continue;
		}
		printf("%d\n",res);
	}
}