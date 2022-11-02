#include<bits/stdc++.h>



#define NN 2222

using namespace std;



int n, m, i, j, x, a=NN, b=NN, c, d, ii, jj, cnt, num;

int dx[3], dy[3];

char s[NN][NN];



int main(){

	

	scanf("%d%d", &n, &m);

	for(i=0; i<n; i++) scanf("%s", s+i);

	

	for(i=0; i<n; i++) for(j=0; j<m; j++) if(s[i][j]=='w'){

		cnt++;

		a=min(a, i), b=min(b, j);

		c=max(c, i), d=max(d, j);

	}

	

	if(cnt==1) {

		for(i=0; i<n; i++) puts(s[i]);

		return 0;

	}

	x=max(c-a+1, d-b+1);

	dx[1]=a, dx[2]=c-x+1;

	dy[1]=b, dy[2]=d-x+1;

	

	if(x>n || x>m) {puts("-1"); return 0;}

	

	for(i=0; i<3; i++){

		for(j=0; j<3; j++){

			if(dx[i]+x>n || dy[j]+x>m) continue;

			num=0;

			

			for(jj=dy[j]; jj<dy[j]+x; jj++) if(s[dx[i]][jj]=='w') num++;

			for(jj=dy[j]; jj<dy[j]+x; jj++)	if(s[dx[i]+x-1][jj]=='w') num++;

			for(ii=dx[i]; ii<dx[i]+x; ii++) if(s[ii][dy[j]]=='w') num++;

			for(ii=dx[i]; ii<dx[i]+x; ii++) if(s[ii][dy[j]+x-1]=='w') num++;

			

			num=num-(s[dx[i]][dy[j]]=='w')-(s[dx[i]+x-1][dy[j]]=='w')-(s[dx[i]][dy[j]+x-1]=='w')-(s[dx[i]+x-1][dy[j]+x-1]=='w');

			

			if(num!=cnt) continue;

			

			for(jj=dy[j]; jj<dy[j]+x; jj++) if(s[dx[i]][jj]!='w') s[dx[i]][jj]='+';

			for(jj=dy[j]; jj<dy[j]+x; jj++)	if(s[dx[i]+x-1][jj]!='w') s[dx[i]+x-1][jj]='+';

			for(ii=dx[i]; ii<dx[i]+x; ii++) if(s[ii][dy[j]]!='w') s[ii][dy[j]]='+';

			for(ii=dx[i]; ii<dx[i]+x; ii++) if(s[ii][dy[j]+x-1]!='w') s[ii][dy[j]+x-1]='+';

			

			for(ii=0; ii<n; ii++) puts(s[ii]);

			return 0;

		}

	}

	puts("-1");

	return 0;

}