#include <iostream>
using namespace std;
int main ()
{int a[2]={0,0},n,p;
cin>>n;
for (int i=0; i<n; i++)
{cin>>p;
if (p==0) a[0]++; else a[1]++;
}
if (a[0]==0) cout<<-1;
else if ((a[1]/9)*9==0) cout<<0; else {for (int i=0; i<(a[1]/9)*9; i++) cout<<5;
for (int i=0; i<a[0]; i++) cout<<0;
}
cout<<endl;
//system ("pause");
return 0;
}