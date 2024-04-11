#include <iostream>
using namespace std;
main()
{int x,ans=0;
cin>>x;
for (int i=5; i>=1; i--){
ans+=x/i;
x=x%i;}
cout<<ans<<endl;

}