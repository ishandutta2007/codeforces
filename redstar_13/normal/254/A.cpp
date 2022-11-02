#include<bits/stdc++.h>



using namespace std;



int n,a,i,x[600010],y[600010],l,flag[5010],id[600010];



int main(){

	

	freopen("input.txt","r",stdin);

	freopen("output.txt","w",stdout);

	

	scanf("%d",&n);

	for(i=0;i<2*n;i++){

		scanf("%d",&a);

		if(!flag[a]){

			x[l++]=i+1;

			id[a]=l-1;

			flag[a]=1;

		}

		else{

			y[id[a]]=i+1;

			flag[a]=0;

		}

	}

	

	

	if(l!=n){

		puts("-1");

		return 0;

	}

	for(i=0;i<n;i++) printf("%d %d\n",x[i],y[i]);

	return 0;

}