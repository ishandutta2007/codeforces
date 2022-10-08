#include<iostream>
using namespace std;
string a,b;
int ans=50000,r;
main()
{cin>>a>>b; r=b.length();
for (int i=0; i<a.length()+b.length(); i++)
{int k=0;
for (int j=0; j<b.length(); j++)
if (j+i-b.length()<a.length() && j+-b.length()>=0) if (b[j]==a[i+j-b.length()]) k++;
ans=min(ans,(int)b.length()-k);
}
cout<<ans<<endl;
}