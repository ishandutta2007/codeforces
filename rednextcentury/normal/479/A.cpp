#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int ans=max(max(a+b+c,a*b*c),max(max((a+b)*c,a*(b+c)),max(a*b+c,a+b*c)));
    cout<<ans<<endl;
}