#include <cstdio>
#include <algorithm>

using namespace std;

int n,k;
int a[200];
double p;

void reverse(int l,int r){
	static int temp;
	for (;l<r;++l,--r)
		swap(a[l],a[r]);
}

double DFS(int depth){
	if (!depth){
		int sum=0;
		for (int i=0;i<n;++i)
			for (int j=i+1;j<n;++j)
				sum+=a[i]>a[j];
		return sum;
	}
	double ret=0;
	for (int i=0;i<n;++i)
		for (int j=i;j<n;++j){
			reverse(i,j);
			ret+=DFS(depth-1);
			reverse(i,j);
		}
	return ret*p;
}

int main(){
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;++i)
		scanf("%d",&a[i]);
	p=n*(n+1)/2;
	p=1/p;
	printf("%.15f",DFS(k));
	return 0;
}