#include<bits/stdc++.h>
using namespace std;
int a[10000][2];
int b[1000];
int ret[1000000];
int main()
{
    int n;
    cin>>n;
    int s1=0,s2=0;
    for (int i=0;i<n-1;i++)
        cin>>a[i][0],s1+=a[i][0];
    for (int i=0;i<n-1;i++)
        cin>>a[i][1],s2+=a[i][1];
    for (int i=0;i<n;i++)
        cin>>b[i];
    int tot=0;
    s1=0;
    ret[tot++]=b[0]+s2;
    for (int i=0;i<n-1;i++)
    {
        s2-=a[i][1];
        s2+=a[i][0];
        ret[tot++]=s2+b[i+1];
    }
    sort(ret,ret+tot);
    cout<<ret[0]+ret[1]<<endl;
}