#include<iostream>
using namespace std;
int b[100009],k=0;
main()
//INETEEN
{int n,ans=0,a;
cin>>n;
for (int i=0; i<2*n; i++)
{cin>>a;
if (b[a]==0) k++;


else k--;
ans=max(ans,k);
b[a]=1;
}
cout<<ans<<endl;
}