#include<iostream>
using namespace std;
int a=-1,b=-1,c=-1,x,n,m,k,l;
main()
{
cin>>n;
for (int i=0; i<n; i++)
{cin>>x;
if (a==-1 || x==a) a=x; else
if (b==-1 || x==b) b=x; else
if (c==-1 || x==c) c=x; else
{cout<<"NO"<<endl; return 0;}
}
if (c==-1) {cout<<"YES"<<endl; return 0;}
if (a>=b && b>=c) {m=a; k=b; l=c;}
if (b>=a && a>=c) {m=b; k=a; l=c;}
if (c>=b && b>=a) {m=c; k=b; l=a;}
if (c>=a && a>=b) {m=c; k=a; l=b;}
if (a>=c && c>=b) {m=a; k=c; l=b;}
if (b>=c && c>=a) {m=b; k=c; l=a;}
if (m-k==k-l) cout<<"YES"<<endl; else cout<<"NO"<<endl;

}