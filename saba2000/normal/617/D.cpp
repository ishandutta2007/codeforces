#include<iostream>
using namespace std;

main()
{int a,b,x,y,m,n;
cin>>a>>b>>x>>y>>m>>n;
if (a==x && x==m || b==y && y==n) cout<<1<<endl; else

if (a==x && (n>=max(b,y) || n<=min(b,y))) cout<<2<<endl; else  
if (m==x && (b>=max(n,y) || b<=min(n,y))) cout<<2<<endl; else
if (a==m && (y>=max(b,n) || y<=min(b,n))) cout<<2<<endl; else
if (b==y && (m>=max(a,x) || m<=min(a,x))) cout<<2<<endl; else
if (b==n && (x>=max(a,m) || x<=min(a,m))) cout<<2<<endl; else
if (n==y && (a>=max(m,x) || a<=min(m,x))) cout<<2<<endl; else
 cout<<3<<endl;
}