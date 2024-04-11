#include <iostream>
#include <algorithm>
using namespace std;
int main ()
{long long int a[2000]={0},m=1,k=2,s=2,an=0;
a[0]=4; a[1]=7;
for (int i=0; i<8; i++)
{m*=10;
for(int j=s; j<s+k; j++)
a[j]=a[s-j+s-1]+m*4;
for(int j=s+k; j<s+k+k; j++)
a[j]=a[s-j+s-1+k]+m*7;
k*=2;
s+=k;
}
sort (a,a+s);
a[s]=4444444444;
long long int r,l;
cin>>r>>l;
for(int i=0; i<=s; i++)
{if (a[i]>=r) {an+=(min(a[i],l)-r+1)*a[i]; r=min(a[i]+1,l+1);}
if (r==l+1) break;
}
cout<<an<<endl;
return 0;
}