#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int odd1=0,even1=0,odd2=0,even2=0;
    while(n--)
    {
        int x;
        cin>>x;
        if (x%2)odd1++;
        else even1++;
    }
    while(m--)
    {
        int x;
        cin>>x;
        if (x%2)odd2++;
        else even2++;
    }
    cout<<min(even1,odd2)+min(odd1,even2)<<endl;
}