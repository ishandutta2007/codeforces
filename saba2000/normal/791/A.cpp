#include<bits/stdc++.h>
using namespace std;
int main()
{long long a,b,ans=0;
cin>>a>>b;
while(a<=b)
{a*=3; b*=2; ans++;}
cout<<ans<<endl;
}