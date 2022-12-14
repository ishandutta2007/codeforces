#include <bits/stdc++.h>
using namespace std;
int is[3000000];
int a[1000000],b[1000000];
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i],is[a[i]]=1;

    for (int i=0;i<n;i++)
        cin>>b[i],is[b[i]]=1;
    int ret=0;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (is[a[i]^b[j]])
                ret++;
        }
    }
    if (ret%2==0)cout<<"Karen"<<endl;
    else cout<<"Koyomi"<<endl;
}