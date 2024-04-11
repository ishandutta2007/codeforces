#include<bits/stdc++.h>



using namespace std;



int n, a, flag[1000010], i, id[1000010][2], mx, cnt, mn=100000010;



int main(){

	

	scanf("%d", &n);

	for(i=0; i<n; i++){

		scanf("%d", &a), flag[a]++;

		if(flag[a]==1) id[a][0]=i+1, id[a][1]=i+1;

		if(flag[a]>1) id[a][1]=i+1;

	}

	for(i=1; i<1000010; i++) if(flag[i]>mx) mx=flag[i];

	

	for(i=1; i<1000010; i++){

		if(flag[i]<mx) continue;

		if(id[i][1]-id[i][0]<mn) mn=id[i][1]-id[i][0], cnt=i;

	}

	

	printf("%d %d\n", id[cnt][0], id[cnt][1]);

	return 0;

}