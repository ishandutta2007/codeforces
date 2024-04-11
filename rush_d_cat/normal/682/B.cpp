#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
typedef __int64 ll;
int a[100000+10];
int main()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    a[0]=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]-a[i-1]>1) a[i]=a[i-1]+1;
    }
    cout<<a[n]+1<<endl;
    return 0;
}