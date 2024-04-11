#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int l,r,a;
    cin>>l>>r>>a;
    if (min(l,r)+a<=max(l,r))
    {
        cout<<(min(l,r)+a)*2<<endl;
    }
    else
    {
        cout<<l+r+a-(l+r+a)%2<<endl;
    }
}