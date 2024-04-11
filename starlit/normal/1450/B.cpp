#include<bits/stdc++.h>
const int N=103;
using namespace std;
int T,n,k,x[N],y[N];
bool fl;
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d%d",&n,&k);
		for(int i=0;i<n;i++){
			scanf("%d%d",x+i,y+i);
		}fl=1;
		for(int i=0;i<n&&fl;i++){
			fl=0;
			for(int j=0;j<n;j++)
			if(abs(x[i]-x[j])+abs(y[i]-y[j])>k)
			fl=1;
		}
		printf("%d\n",fl?-1:1);
	}

}