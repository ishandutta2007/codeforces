#include <bits/stdc++.h>
#include <queue>
# include <algorithm>
using namespace std;
int a[10];
int b[10];
int n;
int ans1[1000000];
int ans2[1000000];
int best2;
int totbest;
int solve()
{
    int ans=0;
    for (int i=1;i<=9;i++)
    {
        int cur=0;
        if (a[i]>0 && b[10-i]>0)
        {
            cur++;
            a[i]--;
            b[10-i]--;
            for (int x=0;x<=9;x++)
                cur+=min(a[x],b[9-x]);
            a[i]++;
            b[10-i]++;
            if (cur>ans)
                best2=i;
            ans=max(ans,cur);
        }
    }
    return ans;
}
void print(int num)
{
    int tot=0;
    while(tot<num)
    {
        ans1[tot]=ans2[tot]=0;
        a[0]--;
        b[0]--;
        tot++;
    }
    if (totbest!=0)
    {
        ans1[tot]=totbest;
        ans2[tot]=10-totbest;
        a[totbest]--;
        b[10-totbest]--;
        tot++;
    }
    for (int i=0;i<=9;i++)
    {
        while(a[i]>0 && b[9-i]>0)
        {
            ans1[tot]=i;
            ans2[tot++]=9-i;
            a[i]--;
            b[9-i]--;
        }
    }
    int cur1=tot;
    int cur2=tot;
    for (int i=0;i<=9;i++)
    {
        while(a[i]>0)
        {
            ans1[cur1++]=i;
            a[i]--;
        }
        while(b[i]>0)
        {
            ans2[cur2++]=i;
            b[i]--;
        }
    }
    for (int i=n-1;i>=0;i--)
        cout<<ans1[i];
    cout<<endl;
    for (int i=n-1;i>=0;i--)
        cout<<ans2[i];
    cout<<endl;
}
int main()
{
    string s;
    cin>>s;
    n=s.length();
    for (int i=0;i<n;i++)
    {
        a[(int)s[i]-'0']++;
        b[(int)s[i]-'0']++;
    }
    int best=0;
    int bestnum=0;
    for (int i=0;i<=a[0];i++)
    {
        a[0]-=i;
        b[0]-=i;
        int cur=solve()+i;
        if (cur>best)
        {
            best=cur;
            bestnum=i;
            totbest=best2;
        }
        a[0]+=i;
        b[0]+=i;
    }
    print(bestnum);
}