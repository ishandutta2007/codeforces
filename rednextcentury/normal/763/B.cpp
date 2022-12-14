#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    cout<<"YES"<<endl;
    for (int i=0;i<n;i++)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        int a=(x1+(1LL<<40))%2;
        int b=(y1+(1LL<<40))%2;
        cout<<a+b*2+1<<endl;
    }
}