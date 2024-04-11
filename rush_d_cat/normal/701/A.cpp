#include<iostream>
using namespace std;
int a[102];
bool used[102];
int main()
{
    int n,sum=0;cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    sum/=(n/2);
    for(int i=1;i<=n;i++)
    {
        if(used[i]) continue;
        used[i]=1;
        for(int j=1;j<=n;j++)
        {
            if(used[j]||(i==j))
            {
                continue;
            }
            if(a[i]+a[j]==sum)
            {
                cout<<i<<" "<<j<<endl;
                used[j]=1;
                break;
            }
        }
    }
    return 0;
}