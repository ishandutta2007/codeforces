#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,d,b;
    cin>>n>>d>>b;
    int cur=0;
    int ret=0;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if (x>d)continue;
        cur+=x;
        if (cur>b)cur=0,ret++;
    }
    cout<<ret<<endl;
}