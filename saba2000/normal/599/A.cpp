#include <iostream>
using namespace std;
main()
{int d1,d2,d3;
cin>>d1>>d2>>d3;
cout<<min(min(2*(d1+d2),d1+d2+d3),min(2*(d2+d3),2*(d1+d3)))<<endl;
}