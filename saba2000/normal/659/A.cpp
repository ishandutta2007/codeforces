#include<iostream>
using namespace std;
main()
{int n,a,b;
cin>>n>>a>>b;
if((1000*n+(a+b))%n==0) cout<<n<<endl;
else cout<<(1000*n+(a+b))%n<<endl;

}