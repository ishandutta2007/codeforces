#include<iostream>
using namespace std;
main()
{int a,b;
cin>>a>>b;
cout<<min(a,b)<<" ";
cout<<(a-min(a,b))/2+(b-min(a,b))/2<<endl;


}