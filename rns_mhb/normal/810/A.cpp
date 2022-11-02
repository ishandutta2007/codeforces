#include<bits/stdc++.h>
using namespace std;

#define ep  0.00000001

int n, k, mark, ans;
double sum;

main(){
	scanf("%d%d",&n,&k);
	for(int i = 0;i < n;i ++) scanf("%d",&mark), sum += mark;
	ans = 2 * n * (k * 1.- 0.5) - 2 * sum;
	if(ans < 0) printf("0");
	else if(fabs(ans *1.-2 * n * (k * 1.- 0.5) + 2 * sum) < ep) printf("%d",ans);
	else printf("%d",ans+1);
}