#include <cstdio>
#include <algorithm>
using namespace std;
#define Maxn 10000
#define eps 1e-7
#define ll long long
int n,k;
int a[Maxn+5];
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	double left=a[1],right=a[n],mid;
	double sum_1,sum_2;
	while(right-left>eps){
		mid=(left+right)/2;
		sum_1=sum_2=0;
		for(int i=1;i<=n;i++){
			if(a[i]<mid){
				sum_1+=mid-a[i];
			}
			else{
				sum_2+=a[i]-mid;
			}
		}
		if(sum_2*(100-k)/100.0>sum_1){
			left=mid;
		}
		else{
			right=mid;
		}
	}
	printf("%.7lf\n",left);
	return 0;
}