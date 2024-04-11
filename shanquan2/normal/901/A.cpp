#include<bits/stdc++.h>
using namespace std;

const int N=201005;
int h,a[N];
int main(){
	scanf("%d",&h);
	for(int i=0;i<=h;i++)scanf("%d",&a[i]);
	bool f=1;int j;
	for(int i=0;i<h;i++)if(a[i]>1&&a[i+1]>1){
		f=0;j=i;
		break;
	}
	if(f){
		printf("perfect\n");
		return 0;
	}
	printf("ambiguous\n");
	int now=0;
	for(int i=0;i<=h;i++){
		for(int k=0;k<a[i];k++)printf("%d ",now);
		now+=a[i];
	}printf("\n");
	now=0;
	for(int i=0;i<=h;i++){
		for(int k=0;k<a[i];k++){
			int t=now;
			if(i==j+1&&k)t--;
			printf("%d ",t);
		}
		now+=a[i];
	}printf("\n");
	return 0;
}