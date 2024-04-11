#include <bits/stdc++.h>
using namespace std;
int num[1000001];
int main()
{
    int n;
    cin>>n;
    int mx=0,ret=-1;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        num[x]++;
        if (num[x]>mx)
            mx=num[x],ret=x;

    }
    cout<<ret<<endl;
}