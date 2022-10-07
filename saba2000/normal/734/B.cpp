#include<iostream>
using namespace std;
main()
{int a,b,c,d,s=0;
cin>>a>>b>>c>>d;
while (c>0 && d>0 && a>0)
{s+=256; c--; d--; a--;}
while (a>0 && b>0)
{s+=32; a--; b--;}
cout<<s<<endl;
}