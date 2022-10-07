#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <iterator>
#include <iomanip>
using namespace std;
int main ()
{int n,an=2,a,b,c,x[100009],h[100009];
cin>>n;
for (int i=0; i<n; i++)
cin>>x[i]>>h[i];
if (n==1) {cout<<1<<endl; return 0;}
for (int i=1; i<n-1; i++)
{if (x[i]-h[i]>x[i-1]) {an++; } else
if (x[i]+h[i]<x[i+1]) {an++; x[i]=x[i]+h[i];}
} 
cout<<an<<endl;
return 0;
}