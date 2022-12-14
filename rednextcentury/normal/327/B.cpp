# include <iostream>
using namespace std;
int main()
{
int n;
cin>>n;
cout<<10000000-n+1;
for (long long i=10000000-n+2;i<=10000000;i++)
{
cout<<" "<<i;
}
cout<<endl;
}