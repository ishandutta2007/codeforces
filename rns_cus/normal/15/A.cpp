#include<stdio.h>
#include<algorithm>
#define M 1000

struct home{
		int x, a;
};
int main()
{
	int n,t;
	scanf("%d%d",&n,&t);
  struct home h[M],tmp;
	int ctn = 0,len;
	for(int i=0;i<n;i++)
	scanf("%d%d",&h[i].x,&h[i].a);
	for(int i=0;i<n;i++)
	for(int j=i+1;j<n;j++)
	if(h[j].x<h[i].x) {tmp=h[i]; h[i] = h[j]; h[j]=tmp;}
	for(int i=0;i<n-1;i++){

   len = (h[i+1].x-h[i].x-t)*2 - (h[i+1].a+h[i].a);

	  if(len == 0)ctn += 1;
		if(len > 0) ctn += 2;
	}
	ctn += 2;
	printf("%d",ctn);
	return 0;
}