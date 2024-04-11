#include <iostream>
using namespace std;
int main ()
{
int n,qula[2]={0};
int k[1000],j;
cin>>n;
j=n-1;
for (int i=0; i<n; i++)
cin>>k[i];
int i=0;
for (int p=0; p<n; p++)
{if (k[i]>k[j]) {qula[p%2]+=k[i]; i++;}
else {qula[p%2]+=k[j]; j--;}
}
cout<<qula[0]<<" "<<qula[1]<<endl;
return 0;
}