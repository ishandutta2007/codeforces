#include<iostream>
#include<cmath>
using namespace std;
main()
{cout.precision(30);
double a,b,c;
cin>>a>>b>>c;
cout<<max((-b+sqrt(b*b-4*a*c))/2/a,(-b-sqrt(b*b-4*a*c))/2/a)<<endl;
cout<<min((-b+sqrt(b*b-4*a*c))/2/a,(-b-sqrt(b*b-4*a*c))/2/a)<<endl;
}