#include <bits/stdc++.h>
using namespace std;

int adj[10000003][2];
int V=1;
int op[10000003];
void add(int x)
{
    int num[30];
    for (int i=0;i<30;i++)
        num[i]=((1<<i)&x)>0;
    int v=0;
    for (int i=29;i>=0;i--)
    {
        if (adj[v][num[i]]==0)
            adj[v][num[i]]=V++;
        op[v]++;
        v=adj[v][num[i]];
    }
    op[v]++;
}
void query(int x)
{
    int num[30];
    for (int i=0;i<30;i++)
        num[i]=((1<<i)&x)>0;
    int v=0;
    long long ret=0;
    for (int i=29;i>=0;i--)
    {
        op[v]--;
        if (adj[v][num[i]]!=0 && op[adj[v][num[i]]])
            v=adj[v][num[i]];
        else
            v=adj[v][1-num[i]],ret+=(1<<i);
    }
    op[v]--;
    cout<<ret<<' ';
}
long long t[1000000];
long long a[1000000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i];
    for (int i=0;i<n;i++){
        cin>>t[i];
        add(t[i]);
    }
    for (int i=0;i<n;i++)
    {
        query(a[i]);
    }
}