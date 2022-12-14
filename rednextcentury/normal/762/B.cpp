#include<bits/stdc++.h>
using namespace std;
vector<int> v1,v2;
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main()
{
    fast_io
    int a,b,c;
    cin>>a>>b>>c;
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        int x;
        string s;
        cin>>x>>s;
        if (s=="USB")
            v1.push_back(x);
        else
            v2.push_back(x);
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    int l1=0,l2=0;
    long long cost=0,num=0;
    while(l1<v1.size() && a)
    {
        a--;
        num++;
        cost+=v1[l1];
        l1++;
    }
    while(l2<v2.size() && b)
    {
        num++;
        b--;
        cost+=v2[l2];
        l2++;
    }
    while(l1<v1.size() || l2<v2.size())
    {
        if (c==0)break;
        c--;
        if (l1<v1.size() && l2<v2.size())
        {
            if (v1[l1]<v2[l2])
                cost+=v1[l1],num++,l1++;
        else
            cost+=v2[l2],num++,l2++;
        }
        else if (l1<v1.size())
            cost+=v1[l1],num++,l1++;
        else
            cost+=v2[l2],num++,l2++;
    }
    cout<<num<<' '<<cost<<endl;
}