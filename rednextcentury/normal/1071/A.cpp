#include <bits/stdc++.h>
using namespace std;
vector<int> ret;
vector<int> ans1,ans2;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    long long a,b;
    cin>>a>>b;
    long long x = a+b;
    long long sum=0;
    for (int i=1;i<=100000;i++)
    {
        sum+=i;
        if (sum>x)break;
        ret.push_back(i);
    }
    for (int i=ret.size()-1;i>=0;i--)
    {
        if (ret[i]<=a)
        {
            ans1.push_back(ret[i]);
            a-=ret[i];
        }
        else
            ans2.push_back(ret[i]);
    }
    cout<<ans1.size()<<endl;
    for (int i=0;i<ans1.size();i++)
        cout<<ans1[i]<<' ';
    cout<<endl<<ans2.size()<<endl;
    for (int i=0;i<ans2.size();i++)
        cout<<ans2[i]<<' ';
    cout<<endl;
}