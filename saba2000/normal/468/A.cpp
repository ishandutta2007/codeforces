#include <iostream>
using namespace std;
int main ()
{int n;
cin>>n;
if (n>=4) {cout<<"YES"<<endl; 
if (n%2==0) {cout<<"1 * 2 = 2"<<endl<<"2 * 3 = 6"<<endl<<"6 * 4 = 24"<<endl;
for (int i=6; i<=n; i+=2)
cout<<i<<" - "<<i-1<<" = 1"<<endl<<"24 * 1 = 24"<<endl;
} else
{cout<<"5 - 3 = 2"<<endl<<"2 + 1 = 3"<<endl<<"2 * 3 = 6"<<endl<<"6 * 4 = 24"<<endl;
for (int i=7; i<=n; i+=2)
cout<<i<<" - "<<i-1<<" = 1"<<endl<<"24 * 1 = 24"<<endl;
}
}
else cout<<"NO"<<endl;
return 0;
}