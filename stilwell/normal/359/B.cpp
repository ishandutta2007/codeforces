#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int A[100000+3],n,K;

int main()
{
scanf("%d%d",&n,&K);
for (int i=1;i<=n;i++) A[i*2-1]=i*2,A[i*2]=i*2-1;
for (int i=1;i<=K;i++) swap(A[i*2-1],A[i*2]);
for (int i=1;i<=n*2;i++) printf("%d ",A[i]);
}