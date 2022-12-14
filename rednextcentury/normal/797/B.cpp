#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int a[1000000];
int main()
{
    int n;
    cin>>n;
    int ans=0;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
        if (a[i]%2==0){
            if (a[i]>0)ans+=a[i];
        }
        else
            v.push_back(a[i]);
    }
    sort(v.begin(),v.end());
    ans+=v[v.size()-1];
    for (int i=(int)v.size()-2;i>=1;i-=2)
    {
        if (v[i]+v[i-1]>0)
            ans+=v[i]+v[i-1];
    }
    cout<<ans<<endl;
}