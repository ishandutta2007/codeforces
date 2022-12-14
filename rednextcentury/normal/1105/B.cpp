#include <bits/stdc++.h>
using namespace std;
string s;
int n,k;
int num[100];
bool check(int x)
{
    for (int i=0;i<26;i++)
        num[i]=0;
    int cur=0;
    for (int i=0;i<n;i++)
    {
        if (i==0 || s[i]==s[i-1])
            cur++;
        else
            cur=1;
        if (cur==k)
            cur=0,num[s[i]-'a']++;
    }
    for (int i=0;i<26;i++)
        if (num[i]>=x)return 1;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    cin>>s;
    int ans=0;
    int l=1,r=n;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if (check(mid))
            ans=mid,l=mid+1;
        else r=mid-1;
    }
    cout<<ans<<endl;
}