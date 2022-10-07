#include<iostream>
using namespace std;
int main ()
{char c,b,m; int k=0;
for (int i=0; i<8; i++)
{cin>>m; c=m;
for (int j=0; j<7; j++)
{cin>>b; if (b==c) k=1; c=b;
} if (m==c) k=1;
}
if (k==1) cout<<"NO"<<endl; else cout<<"YES"<<endl;
return 0;
}