#include <iostream>
using namespace std;
int n,min1,min2,min3,max1,max2,max3,a,b,c;
int main()
{cin>>n>>min1>>max1>>min2>>max2>>min3>>max3;
a=max(min(n-min2-min3,max1),min1);
b=max(min(n-min3-a,max2),min2);
c=n-a-b;
cout<<a<<" "<<b<<" "<<c<<endl;
return 0;
}