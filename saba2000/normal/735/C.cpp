#include<iostream>
#include<cmath>
using namespace std;
main()
{long long n,g=2,k=1;
cin>>n;
for (int i=1; i<=n+1; i++)
{if (g>n) {cout<<i-1<<endl; return 0;}
g=g+k;
k=g-k;
}
}