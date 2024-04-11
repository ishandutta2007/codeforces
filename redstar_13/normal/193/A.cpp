#include<bits/stdc++.h>



#define NN 55

using namespace std;



char mat[NN][NN];

int vst[NN][NN];



int dx[]={-1, 0, 0, 1}, dy[]={0, -1, 1, 0};



void dfs(int u, int v){

	

	vst[u][v]=1;

	for(int i=0; i<4; i++){

		int uu=u+dx[i], vv=v+dy[i];

		if(vst[uu][vv]) continue;

		if(mat[uu][vv]=='#') dfs(uu, vv);

	}

	

}

int main(){

	int n,m,i,j;

	cin>>n>>m;



	int cnt=0;

	for(i=0; i<n; i++) {

		scanf("%s", mat+i);

		for(j=0; j<m; j++) if(mat[i][j]=='#') cnt++;

	}

	

	if(cnt<=2) {puts("-1"); return 0;}

	for(i=0; i<n; i++){

		for(j=0; j<m; j++){

			if(mat[i][j]!='#') continue;

			mat[i][j]='.';

			memset(vst, 0 ,sizeof(vst));

			

			int ok=1;

			for(int k=0; k<n && ok; k++){

				for(int p=0; p<m && ok; p++){

					if(mat[k][p]=='#' && ok) {

						dfs(k,p);

						ok=0;

					}

				}

			}

			

			ok=0;

			for(int k=0; k<n; k++){

				for(int p=0; p<m; p++){

					if(mat[k][p]=='#' && vst[k][p]==0) ok=1;

				}

			}

			

			if(ok) {puts("1"); return 0;}

			mat[i][j]='#';

		}	

	}

	puts("2");

	return 0;

}