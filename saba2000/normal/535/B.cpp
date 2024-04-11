#include<iostream>
using namespace std;
int main ()
{int n,s[2000],m=2,k=1,l=1,p;
s[0]=4; s[1]=7;
cin>>n;
for (int i=0;i<8; i++)
{k*=2; l=l*10; p=m;
for (int j=p-k; j<p; j++)
{s[m]=l*4+s[j];
m++;
}
for (int j=p-k; j<p; j++)
{s[m]=l*7+s[j];
m++;
}
}
for (int i=0; i<m; i++)
{if(n==s[i])
cout<<i+1<<endl;
}
//system ("pause");
return 0;
}