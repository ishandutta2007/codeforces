#include<bits/stdc++.h>
using namespace std;

int n,m,c,z,a[1005];
int main(){
	scanf("%d%d%d",&n,&m,&c);
	for(int i=1;i<=n;i++)a[i]=-1;
	z=c/2;
	int s=1,t=n;
	for(int i=1;i<=m;i++){
		int x;scanf("%d",&x);
		if(x>z){
			int j;
			for(j=n;j>t;j--)if(a[j]<x)break;
			printf("%d\n",j);fflush(stdout);
			a[j]=x;if(j==t)t--;
		}else{
			int j;
			for(j=1;j<s;j++)if(a[j]>x)break;
			printf("%d\n",j);fflush(stdout);
			a[j]=x;if(j==s)s++;
		}
		bool f=1;
		for(int i=1;i<=n;i++){
			if(a[i]==-1){f=0;break;}
			if(i<n&&a[i]>a[i+1]){f=0;break;}
		}
		if(f)break;
	}
	return 0;
}