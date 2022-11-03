#include<bits/stdc++.h>
using namespace std;

struct fe{
	int x,id;
}a[25],b[25];
bool cmp1(fe x,fe y){
	return x.x<y.x;
}
bool cmp2(fe x,fe y){
	return x.id<y.id;
}
int n;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i].x),a[i].id=i;
	sort(a,a+n,cmp1);
	for(int i=1;i<n;i++)if(a[i-1].x==a[i].x){
		printf("-1\n");
		return 0;
	}
	for(int i=0;i<n;i++)b[i]=(fe){a[(i+1)%n].x,a[i].id};
	sort(b,b+n,cmp2);
	for(int i=0;i<n;i++)printf("%d ",b[i].x);
	return 0;
}