#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int i,j,n,m,t,x[6666],y[6666];
ll res,sb[6][6],k,kk;

int main() {
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d",&x[i],&y[i]);
		x[i]/=2;
		y[i]/=2;
		
		j=(x[i]&1);
		k=(y[i]&1);
		sb[j][k]++;
	}
	
	for(i=0;i<=1;i++){
		for(j=0;j<=1;j++){
			k=sb[i][j];
			res+=k*(k-1)*(k-2)/6;
			
			for(int ii=0;ii<=1;ii++){
				for(int jj=0;jj<=1;jj++){
					kk=sb[ii][jj];
					
					if(ii==i&&jj==j){continue;}
					res+=k*(k-1)/2*kk;
				}
			}
		}
	}
	
	printf("%lld",res);
}