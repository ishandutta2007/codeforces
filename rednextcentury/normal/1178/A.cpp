#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector<int> ret;
    ret.push_back(1);
    int alice;
    cin>>alice;
    int sum=alice;
    int cur=alice;
    for (int i=1;i<n;i++)
    {
        int x;
        cin>>x;
        sum+=x;
        if (x*2<=alice)cur+=x,ret.push_back(i+1);

    }
    if (cur*2>sum)
    {
        cout<<ret.size()<<endl;
        for (auto x:ret)cout<<x<<' ';
    }
    else
        cout<<0<<endl;
}