#include <iostream>
using namespace std;
int main ()
{int n,m,k,n1,m1,p1=0,p2=0,lc,a,b;
cin>>n>>m; k=n+m;  n1=n; m1=m;
n--; lc=1;
for (int i=0; i<k-1; i++)
{ if (m==0 && lc==1) {n--; p1++; lc=1;} else
 if (m==0 && lc==0) {n--; p2++; lc=1; } else 
 if (n==0 && lc==1) {m--; p2++; lc=0;} else
 if (n==0 && lc==0) {m--; p1++; lc=0;} else 
if (lc==1 && i%2==0) {m--; lc=0; p2++;} else
 if (lc==0 && i%2==0) {n--; lc=1; p2++;}else
 if (lc==1 && i%2==1) {n--; p1++;} else
 {m--; p1++;}
}
n=n1; m=m1;
a=p1; b=p2;
p1=0; p2=0;
m--; lc=0;
for (int i=0; i<k-1; i++)
{ if (m==0 && lc==1) {n--; p1++; lc=1;} else
 if (m==0 && lc==0) {n--; p2++; lc=1; } else 
 if (n==0 && lc==1) {m--; p2++; lc=0;} else
 if (n==0 && lc==0) {m--; p1++; lc=0;} else 
if (lc==1 && i%2==0) {m--; lc=0; p2++;} else
 if (lc==0 && i%2==0) {n--; lc=1; p2++;}else
 if (lc==1 && i%2==1) {n--; p1++;} else
 {m--; p1++;}
}
if (p1>a)
cout<<p1<<" "<<p2<<endl;
else cout<<a<<" "<<b<<endl;
return 0;
}