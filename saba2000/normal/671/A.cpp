#include<iostream>
#include<cmath>
using namespace std;
double f(double  x, double y, double a, double b)
{return sqrt((x-a)*(x-a)+(y-b)*(y-b));}
double n,ax,ay,bx,by,tx,ty,ans=0,ff[100000],q,s;
int p,l;
double a[100000],a1[100000];
double b[100000],b1[100000];
main()
{
cin>>ax>>ay>>bx>>by>>tx>>ty;
cin>>n;
for (int i=0; i<n; i++)
{cin>>a[i]>>b[i];
a1[i]=f(tx,ty,a[i],b[i])-f(ax,ay,a[i],b[i]);
b1[i]=f(tx,ty,a[i],b[i])-f(bx,by,a[i],b[i]);}

int e1=0,e2=-1,e3=0,e4=-1;
for (int i=0; i<n; i++)
if (a1[i]>a1[e1]) e1=i;
for (int i=0; i<n; i++)
if ((e2==-1 || b1[i]>b1[e2]) && e1!=i && b1[i]>0) e2=i;
for (int i=0; i<n; i++)
if (b1[i]>b1[e3]) e3=i;
for (int i=0; i<n; i++)
if ((e4==-1 || a1[i]>a1[e4]) && e3!=i) e4=i;
if (a1[e1]+max(b1[e2],(double)0)>b1[e3]+max(a1[e4],(double)0)) {ff[e1]=1 ;
//cout<<e1<<" "<<e2<<"  "<<a1[e1]<<" "<<b1[e2]<<endl; 
ans+=f(ax,ay,a[e1],b[e1])+f(tx,ty,a[e1],b[e1]); if (b1[e2]>0) {ff[e2]=1; ans+=f(bx,by,a[e2],b[e2])+f(tx,ty,a[e2],b[e2]);}}
else {ff[e3]=1; 
//cout<<e3<<" "<<e4<<"  "<<a1[e3]<<" "<<b1[e4]<<endl; 
ans+=f(bx,by,a[e3],b[e3])+f(tx,ty,a[e3],b[e3]);if (a1[e4]>0) {ff[e4]=1;
ans+=f(ax,ay,a[e4],b[e4])+f(tx,ty,a[e4],b[e4]);}
}
for (int i=0; i<n; i++)
{if (ff[i]==1) continue;
ans+=2*f(tx,ty,a[i],b[i]);
//cout<<2*f(tx,ty,a[i],b[i])<<endl;
}
printf("%0.12lf\n",ans);
}