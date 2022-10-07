#include<bits/stdc++.h>
using namespace std;
int k;
main()
{cin>>k;
int ans=0;
for (int i=0; i<k; i++)
{
    int a;
    cin>>a;
    ans=max(ans,a-25);
}
cout<<ans<<endl;
}