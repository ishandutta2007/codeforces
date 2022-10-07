#include<iostream>
#include<iomanip>

using namespace std;
main()
{double n; int t;
cout.precision(100);
cin>>n>>t;
for (int i=0; i<t/5000; i++)
n*=1.0000550015122252129122078638524;
for (int j=0; j<t%5000; j++)
n*= 1.000000011000000000000000000000;
cout<<n<<endl;
}