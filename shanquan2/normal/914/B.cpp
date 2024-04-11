#include<bits/stdc++.h>
using namespace std;

int n,a[100005],b[100005];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]),b[a[i]]++;
	for(int i=1;i<=100000;i++)if(b[i]&1){
		printf("Conan\n");
		return 0;
	}
	printf("Agasa\n");
	return 0;
}