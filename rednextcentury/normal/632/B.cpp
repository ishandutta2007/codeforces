#include<bits/stdc++.h>
using namespace std;
long long preA[1000000];
long long preB[1000000];
long long sufA[1000000];
long long sufB[1000000];
long long a[1000000];
int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i];
    string s;
    cin>>s;
    for (int i=0;i<n;i++)
    {
        if (s[i]=='A')
            preA[i]+=a[i];
        else
            preB[i]+=a[i];
        if(i>0)
            preA[i]+=preA[i-1],preB[i]+=preB[i-1];
    }
    for (int i=n-1;i>=0;i--)
    {
        if (s[i]=='A')
            sufA[i]+=a[i];
        else
            sufB[i]+=a[i];
        if(i<n-1)
            sufA[i]+=sufA[i+1],sufB[i]+=sufB[i+1];
    }
    long long ans=preB[n-1];
    for (int i=0;i<n;i++)
    {
        ans=max(ans,preB[i]+sufA[i+1]);
        ans=max(ans,preA[i]+sufB[i+1]);
    }
    cout<<ans<<endl;
}