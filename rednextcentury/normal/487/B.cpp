#include <bits/stdc++.h>
using namespace std;
int a[1000000];
int dp[1000000];
deque<int> q;
void add(int id)
{
    while(!q.empty() && dp[q.back()]>=dp[id])
        q.pop_back();
    q.push_back(id);
}
int query(int mn)
{
    while(!q.empty() && q.front()<mn)
        q.pop_front();
    if (q.empty())return 1e9;
    return dp[q.front()];
}
deque<int> q2;
void add2(int id)
{
    while(!q2.empty() && a[q2.back()]>=a[id])
        q2.pop_back();
    q2.push_back(id);
}
int query2(int mn)
{
    while(!q2.empty() && q2.front()<mn)
        q2.pop_front();
    if (q2.empty())return 1e9;
    return a[q2.front()];
}
deque<int> q3;
void add3(int id)
{
    while(!q3.empty() && a[q3.back()]<=a[id])
        q3.pop_back();
    q3.push_back(id);
}
int query3(int mn)
{
    while(!q3.empty() && q3.front()<mn)
        q3.pop_front();
    if (q3.empty())return -1e9;
    return a[q3.front()];
}
int main()
{
    ios_base::sync_with_stdio(0);
    multiset<int> s;
    multiset<int> best;
    int n,dif,len;
    cin>>n>>dif>>len;
    dp[0]=0;
    for (int i=1;i<=n;i++)
        cin>>a[i];

    int l=1;
    for (int r=1;r<=n;r++)
    {
        if (r-len>=0)add(r-len);
        add2(r);
        add3(r);
        while(query3(l)-query2(l) > dif)
        {
            l++;
        }
        dp[r]=query(l-1)+1;
    }
    if (dp[n]>=1e9)dp[n]=-1;
    cout<<dp[n]<<endl;
}