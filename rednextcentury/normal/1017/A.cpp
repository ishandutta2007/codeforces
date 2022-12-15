#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int s=a+b+c+d;
    int ret=1;
    for (int i=1;i<n;i++)
    {
        cin>>a>>b>>c>>d;
        if (a+b+c+d>s)ret++;
    }
    cout<<ret<<endl;
}