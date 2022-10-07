#include<iostream>
using namespace std;
int n,x,y,a[8],b[8],p,q,k[8];
char c[8],s;
main()
{
cin>>n>>x>>y;
for (int i=0; i<n;i++){cin>>s>>p>>q;
if (p==x && q>y && (q<b[0] || k[0]==0)) {c[0]=s; a[0]=p; b[0]=q; k[0]=1;} else
if (p==x && q<y && (q>b[1]|| k[1]==0)) {c[1]=s; a[1]=p; b[1]=q; k[1]=1;} else
if (q==y && p>x && (p<a[2]|| k[2]==0)) {c[2]=s; a[2]=p; b[2]=q; k[2]=1;} else
if (q==y && p<x && (p>a[3]|| k[3]==0)) {c[3]=s; a[3]=p; b[3]=q;k[3]=1;} else
if (p-x==q-y && p>x && (p<a[4]|| k[4]==0)) {c[4]=s; a[4]=p; b[4]=q;k[4]=1;} else
if (p-x==q-y && p<x && (p>a[5]|| k[5]==0)) {c[5]=s; a[5]=p; b[5]=q;k[5]=1;} else
if (p+q==x+y && p>x && (p<a[6] || k[6]==0)) {c[6]=s; a[6]=p; b[6]=q;k[6]=1;} else
if (p+q==x+y && p<x && (p>a[7] || k[7]==0)) {c[7]=s; a[7]=p; b[7]=q;k[7]=1;}
}
//cout<<c[0]<<" "<<c[1]<<" "<<c[2]<<" "<<c[3]<<" "<<c[4]<<" "<<c[5]<<" "<<c[6]<<" "<<c[7]<<endl;
if 
(c[0]=='R' || c[0]=='Q' ||
c[1]=='R' || c[1]=='Q' ||
c[2]=='R' || c[2]=='Q' ||
c[3]=='R' || c[3]=='Q' ||
c[4]=='B' || c[4]=='Q' ||
c[5]=='B' || c[5]=='Q' ||
c[6]=='B' || c[6]=='Q' ||
c[7]=='B' || c[7]=='Q') cout<<"YES"<<endl; else cout<<"NO"<<endl;
 }