#include<bits/stdc++.h>
using namespace std;

int n,a[10005],b[10005],c[10005],p[10005],ans[10005];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		printf("? %d %d\n",0,i);
		fflush(stdout);
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++){
		printf("? %d %d\n",i,0);
		fflush(stdout);
		scanf("%d",&c[i]);
	}
	int tmp=0;
	for(int i=0;i<n;i++){
		bool f=1;
		p[0]=i;
		for(int j=0;j<n;j++){
			b[j]=p[0]^a[j];
			if(b[j]<0||b[j]>=n){f=0;break;}
		}
		if(!f)continue;
		for(int j=0;j<n;j++)p[b[j]]=j;
		for(int j=0;j<n;j++)if((b[0]^p[j])!=c[j]){f=0;break;}
		if(!f)continue;
		if(f){
			for(int j=0;j<n;j++)ans[j]=p[j];
			tmp++;
		}
	}
	printf("!\n%d\n",tmp);
	for(int i=0;i<n;i++)printf("%d ",ans[i]);printf("\n");
	fflush(stdout);
	return 0;
}