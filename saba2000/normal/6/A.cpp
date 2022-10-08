#include <iostream>
using namespace std;
int main ()
{int a,b,c,d;
cin>>a>>b>>c>>d;
if ((a+b>c && a+c>b && b+c>a) || (a+d>c && a+c>d && d+c>a) || (d+b>c && d+c>b && b+c>d) || (a+b>d && a+d>b && b+d>a)) cout<<"TRIANGLE"<<endl; else 
if (a+b==c || a+c==b || b+c==a || a+d==c || a+c==d ||  d+c==a || d+b==c || d+c==b || b+c==d || a+b==d || a+d==b || b+d==a) cout<<"SEGMENT"<<endl; else
cout<<"IMPOSSIBLE"<<endl;
return 0;
}