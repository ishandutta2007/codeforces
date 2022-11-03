#include<cstdio>
using namespace std;

int a[1000];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	bool f=0;
	for(int i=0;i<n;i++){
		for(int j=i+2;j<n-1;j++){
			int max=(a[i]>a[i+1])?a[i]:a[i+1];
			int min=a[i]+a[i+1]-max;
			if((a[j]>min && a[j]<max)&& !(a[j+1]>min && a[j+1]<max) || !(a[j]>min && a[j]<max)&& (a[j+1]>min && a[j+1]<max)){
				f=1;
				break;
			}
		}
		if(f) break;
	}
	if(f)printf("yes\n");else printf("no\n");
	return 0;
}