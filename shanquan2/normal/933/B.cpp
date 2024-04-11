#include<bits/stdc++.h>
using namespace std;

long long p;
int k,n,a[100005];
int main(){
	scanf("%I64d%d",&p,&k);
	while(p){
		if(n&1){
			if(p%k==0){
				a[n]=0;
				p/=k;
			}else{
				a[n]=k-p%k;
				p=p/k+1;
			}
		}else{
			a[n]=p%k;
			p/=k;
		}
		n++;
	}
	printf("%d\n",n);
	for(int i=0;i<n;i++)printf("%d ",a[i]);printf("\n");
	return 0;
}