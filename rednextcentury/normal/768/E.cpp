#include<bits/stdc++.h>
using namespace std;
int main()
{
    int grundy[]={0,1,1,2,2,2,3,3,3,3,4,4,4,4,4,5,5,5,5,5,5,6,6,6,6,6,6,6,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,9,9,9,9,9,9,9,9,9,9,10,10,10,10,10,10,10,10,10,10,10};
    int n;
    cin>>n;
    int ret=0;
    for (int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        ret^=grundy[x];
    }
    if (ret==0)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}