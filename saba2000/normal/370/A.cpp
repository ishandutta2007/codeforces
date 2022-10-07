#include <iostream>
#include <cmath>
using namespace std;
int main ()
{int a,b,x,y;
cin>>a>>b>>x>>y;
if (a==x || b==y) cout<<"1 "; else cout<<"2 ";
if ((a+b)%2!=(x+y)%2) cout<<"0 "; else if (abs(a-x)==abs(b-y)) cout<<"1 "; else cout<<"2 ";
cout<<max(abs(a-x),abs(b-y))<<endl;
return 0;
}