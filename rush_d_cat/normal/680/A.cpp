#include<iostream>
#include<cstdio>
using namespace std;
int a[101];
int main()
{
    memset(a,0,sizeof(a));
    for(int i=1;i<=5;i++){
        int tmp;cin>>tmp;
        a[tmp]++;
    }
    int res=0,maxn=0;
    for(int i=1;i<=100;i++)
    {
        res+=(a[i]*i);
        if(a[i]<=3&&a[i]>=2) maxn=max(maxn,i*a[i]);
        if(a[i]>=4) maxn=max(maxn,3*i);
    }
    res -= maxn;
    cout<<res<<endl;
    return 0;
}