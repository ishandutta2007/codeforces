#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int a[10000];
int num[10010];
int t[1000][2];
int main()
{
    fast;
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
        num[a[i]]++;
    }
    int ret=0;
    bool p=0;
    bool can=0;
    int id=0;
    for (int i=0;i<=100;i++)
    {
        if (num[i]>2 || num[i]==1)
        {
            if (num[i]>=3 && can==0)
            {
                t[i][0]=num[i];
                can=1;
                id=i;
                continue;
            }
            t[i][p]=1;
            t[i][!p]=num[i]-1;
            ret++;
            p=!p;
        }
        else
        {
            t[i][0]=num[i];
        }
    }
    if (can && ret%2)
    {
        t[id][1]=1;
        t[id][0]=num[id]-1;
        ret=0;
    }
    if (ret%2)
        cout<<"NO"<<endl;
    else
    {
        cout<<"YES"<<endl;
        for (int i=0;i<n;i++)
        {
            if (t[a[i]][0]>0)
            {
                t[a[i]][0]--;
                cout<<"A";
            }
            else
            {
                t[a[i]][1]--;
                cout<<"B";
            }
        }
        cout<<endl;
    }
}