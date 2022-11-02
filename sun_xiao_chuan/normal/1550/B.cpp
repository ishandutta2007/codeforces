#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,x,y,a[666],res;


int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&x,&y);
		m=0;
		scanf("%1d",&a[1]);
		for(i=2;i<=n;i++){
			scanf("%1d",&a[i]);
			if(a[i]!=a[i-1]){
				m++;
			}
		}
		m++;
		m=m/2+1;
		res=x*n+max(y*n,y*m);
		printf("%d\n",res);
	}
}