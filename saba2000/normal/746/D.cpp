#include<bits/stdc++.h>
using namespace std;
int main()
{int n,a,b,k; char x='G',y='B';
cin>>n>>k>>a>>b;
if (a>b) {swap(a,b); swap(x,y);}

int A=a+1;int X;
for (X=a+1;X>=0; X--)
if ((b-X)%A==0) break;
int p=(b-X)/A+1;
//cout<<X<<" "<<p<<endl;
//cout<<a<<endl;

if (p>k) {cout<<"NO"<<endl; return 0;}
for (int i=1; i<=a+1; i++)
{//out<<p-(int)(i>X);
for (int j=0; j<p-(int)(i>X); j++)
cout<<y;
if (i!=a+1) cout<<x;
}
}
//PX+(A-X)(P-1)=b;
//PX+AP-PX+X-A=b;
//b-X=A(P-1)