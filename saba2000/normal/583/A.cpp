#include <iostream>
using namespace std;
int main()
{int k[60]={0},p[60]={0},a,b;
int n;
cin>>n;
for (int i=0; i<n*n; i++)
{cin>>a>>b;
if (k[a]+p[b]==0) {cout<<i+1<<" "; k[a]++; p[b]++;}
}
}