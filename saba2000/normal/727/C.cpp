#include<iostream>
using namespace std;
main ()
{int n,a[10000];
cin>>n;
for (int i=1; i<=n; i+=3)
{int x,y,z;
if (i+2<=n) {cout<<"? "<<i<<" "<<i+1<<endl; fflush(stdout);
cin>>x;
cout<<"? "<<i<<" "<<i+2<<endl; fflush(stdout);
cin>>y;
cout<<"? "<<i+2<<" "<<i+1<<endl; fflush(stdout);
cin>>z;
a[i]=(x+y-z)/2;
a[i+1]=(x+z-y)/2;
a[i+2]=(y+z-x)/2;
} 
if (i+1==n)
{
cout<<"? "<<i<<" "<<i+1<<endl; fflush(stdout);
cin>>x;
cout<<"? "<<i<<" "<<i-1<<endl; fflush(stdout);
cin>>y;           
a[i]=y-a[i-1];
a[i+1]=x-a[i];
}
if (i==n)
{cout<<"? "<<i<<" "<<i-1<<endl; fflush(stdout);
cin>>x;
a[i]=x-a[i-1];
}}
cout<<"! ";
for (int i=1; i<=n; i++)
cout<<a[i]<<" ";

}