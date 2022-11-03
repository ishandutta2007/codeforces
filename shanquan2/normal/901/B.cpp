#include<bits/stdc++.h>
using namespace std;

int n,a[205],b[205],c[205];
int main(){
	scanf("%d",&n);
	a[1]=b[0]=1;
	for(int i=2;i<=n;i++){
		memcpy(c,b,sizeof(c));
		memcpy(b,a,sizeof(a));
		for(int j=i;j;j--)a[j]=a[j-1];a[0]=0;
		bool f=1;
		for(int j=0;j<=i;j++){
			if(abs(a[j]+c[j])>1){f=0;break;}
		}
		if(f){
			for(int j=0;j<=i;j++)a[j]+=c[j];
		}else{
			for(int j=0;j<=i;j++)a[j]-=c[j];
		}
	}
	printf("%d\n",n);
	for(int i=0;i<=n;i++)printf("%d ",a[i]);printf("\n");
	printf("%d\n",n-1);
	for(int i=0;i<n;i++)printf("%d ",b[i]);printf("\n");
	return 0;
}