#include <iostream>
using namespace std;
int main () {
int n,m[26]={0},r=0,i;
char a,b;
cin>>n;
for (i=0; i<n-1; i++)
{cin>>a>>b;
m[a-97]++;
if (m[b-65]==0) r++;
else m[b-65]--; }
cout<<r;}