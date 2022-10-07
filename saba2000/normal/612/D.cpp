#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std; 
int a[1000000],b[1000000],n,k,p,q,c[2000000],d[2000000],s,x,y=-1,r,ans,ans1[1000000],ans2[1000000];
main()
{
scanf("%d",&n);
scanf("%d",&r);
for (int i=0; i<n; i++)
{scanf("%d",&a[i]);
scanf("%d",&b[i]);}
sort(a,a+n);
sort(b,b+n);
while(p<n || q<n)
{if ((a[p]<=b[q] || q==n) && p<n) {c[k]=a[p]; p++; d[k]=1;} else
{c[k]=b[q]; q++; d[k]=-1;}
k++;}
for (int i=0; i<2*n; i++)
{
int j=i;
while(c[j]==c[i]) {s+=d[j]; if (s>=r && y==-1) {x=c[i]; y=0;} j++; }
if (s>=r && y==-1) {x=c[i]; y=0;}
if (s<r && y==0) {ans1[ans]=x; ans2[ans]=c[i]; ans++; y=-1;}
i=j-1;
}
printf("%d",ans);
printf("\n");
for (int i=0; i<ans; i++)
{printf("%d",ans1[i]);
printf(" ");
printf("%d",ans2[i]);
printf("\n");}
}