#include<bits/stdc++.h>
using namespace std;

int n;
bool a[300005];
int main(){
	scanf("%d",&n);
	int j=n;
	printf("1 ");
	for(int i=0;i<n;i++){
		int x;scanf("%d",&x);
		a[x]=1;
		while(j&&a[j])j--;
		printf("%d ",i-(n-j)+2);
	}
	printf("\n");
	return 0;
}