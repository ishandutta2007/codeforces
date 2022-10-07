#include<bits/stdc++.h>
using namespace std;
pair<double,double> b[100009];
double v[100009],a[100009],n,L,R=0,Vl,Vr,ans;
double E=0.0000001;
main()
//INETEEN
{cin>>n;
for (int i=0; i<n; i++)
cin>>a[i];
for (int i=0; i<n; i++)
cin>>v[i];

double X=0,Y=1000000000;
while(Y-X>E)
{double z=(X+Y)/2,P=0;
double x=a[0]-v[0]*z,y=a[0]+v[0]*z;
for (int i=1; i<n; i++)
{double p=a[i]-v[i]*z,q=a[i]+v[i]*z;
if (p>y || q<x) P=1;
x=max(x,p); y=min(y,q);
}
if (P==0) Y=z;
else X=z;	
}
cout.precision(20);
cout<<X<<endl;
}