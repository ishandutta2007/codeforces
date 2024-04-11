#include<iostream>
using namespace std;
main()
{
int n,k;
cin>>n>>k;
int x=(240-k)/5;
for(int i=1; i<=n; i++)
if(i*(i+1)>2*x) {cout<<i-1<<endl;return 0;}
cout<<n<<endl;
}