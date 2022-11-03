#include<cstdio>
using namespace std;

int a[100000];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		a[i%k]+=x;
	}
	int min=0;
	for(int i=1;i<k;i++)
		if(a[i]<a[min])min=i;
	printf("%d\n",min+1);
	return 0;
}