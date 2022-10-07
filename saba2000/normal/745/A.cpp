#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
string a[1009];
int ans;
main()
{string s;
cin>>s;
for (int i=0; i<s.length(); i++)
for (int j=i; j<s.length()+i; j++){
a[i]+=s[j%(int)s.length()];

//cout<<a[i]<<endl;
}

sort(a,a+(int)s.length());
ans=1;
for (int i=1; i<s.length(); i++)
if (a[i]!=a[i-1]) ans++;
cout<<ans<<endl;
//system("pause");
}