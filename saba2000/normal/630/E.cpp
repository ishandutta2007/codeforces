#include<iostream>
using namespace std;
main()
{long long a,b,x,y;
cin>>a>>b>>x>>y;
cout<<((x-a+1)/2)*((y-b+1)/2)+((x-a+2)/2)*((y-b+2))/2<<endl;
}