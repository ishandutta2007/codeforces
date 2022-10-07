#include <iostream>
using namespace std;
int main ()
{long long int n,k[20]={0},m[20]={0},a=0;
long long int an=0; cin>>n;
for (int i=0; i<n; i++)
{int p; cin>>p; if (p==0) a++; if (p>0) k[p]++; else m[-p]++;}
for (int i=1; i<=10; i++)
{an+=m[i]*k[i];
}
cout<<an+(a*(a-1)/2)<<endl;
return 0;
}