#include <bits/stdc++.h>
using namespace std;
long long a[1000000];
map<int,int> mp;
int main()
{
    int n;
    cin>>n;
    long long sum=0;
    long long num=0;
    string B="cslnb";
    string A="sjfnb";
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
        num+=a[i]-i;
        mp[a[i]]++;
    }
    if (sum==0 || mp[0]>=2)
    {
        cout<<B<<endl;
        return 0;
    }
    int X=0;
    for (auto p:mp)
    {
        if (p.second>2)
        {
            cout<<B<<endl;
            return 0;
        }
        if (p.second==2)X++;
        if (p.second==2 && mp[p.first-1]>0)
        {
            cout<<B<<endl;
            return 0;
        }
    }
    if (X>1){
        cout<<B<<endl;
        return 0;
    }
    if (num%2==0)
    {
        cout<<B<<endl;
    }
    else cout<<A<<endl;

}