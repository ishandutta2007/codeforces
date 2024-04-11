#include<bits/stdc++.h>



#define NN 1111

using namespace std;

typedef long long INT;



int mat[NN][NN], row[NN], col[NN];



int main(){

	int n,m,k,i,j;

	cin>>n>>m>>k;

	for(i=0; i<n; i++){

		for(j=0; j<m; j++){

			scanf("%d", mat[i]+j);

		}

	}

	

	for(i=0; i<n; i++) row[i]=i;

	for(i=0; i<m; i++) col[i]=i;

	

	while(k--){

		int x,y;

		char key;

		scanf(" %c %d %d", &key, &x, &y); x--; y--;

		if(key=='r') swap(row[x], row[y]);

		else if(key=='c') swap(col[x], col[y]);

		else printf("%d\n", mat[row[x]][col[y]]);

	}

	

	return 0;

}