#include <bits/stdc++.h>
using namespace std;
int num[5000001];
vector<int> vec;
int main()
{
    int n=5000000;
    int t=0,f=0;
    for (int i=1;i<=n;i++)
    {
        int x=i,y=i;
        while (x%2==0)x/=2,t++;
        while (y%5==0)y/=5,f++;
        num[i]=min(t,f);
    }
    int m;
    cin>>m;
    for (int i=0;i<n;i++)
    {
        if (num[i]==m)
            vec.push_back(i);
    }
    cout<<vec.size()<<endl;
    for (int i=0;i<vec.size();i++)
        cout<<vec[i]<<" ";
    cout<<endl;
}