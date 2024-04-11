#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int A[101],n;
int main(){
for(int k=0;k<1000000;++k) random_shuffle(A,A+100);
scanf("%d",&n);
for(int i=0;i<n;++i) scanf("%d",A+i);

sort(A,A+n);
for(int i=0;i<n;++i) printf("%d%c",A[i],i==n-1?'\n':' ');
return 0;
}