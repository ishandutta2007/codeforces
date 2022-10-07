#include<cmath>
#include<iostream>
using namespace std;
main()
{string s;
int ans=0;
char k='a';
cin>>s;
for (int i=0 ;i<s.length(); i++)
{ans+=min(abs(k-s[i]),26-abs(k-s[i]));
k=s[i];
}
cout<<ans<<endl;
}