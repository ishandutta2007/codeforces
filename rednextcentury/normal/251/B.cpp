#include<bits/stdc++.h>
using namespace std;
int p[1000000];
int q[1000000];
int s[1000000];

int tmp[1000000];
int n,k;
bool eq()
{
    for (int i=1;i<=n;i++)
        if (p[i]!=s[i])
            return 0;
    return 1;
}
void rb()
{
    for (int i=1;i<=n;i++)
        tmp[i]=p[i];
    for (int i=1;i<=n;i++)
        p[q[i]]=tmp[i];
}
void mv()
{
    for (int i=1;i<=n;i++)
        tmp[i]=p[i];
    for (int i=1;i<=n;i++)
        p[i]=tmp[q[i]];
}
int solve1()
{
    int step=0;
    do
    {
        if (eq()) return step;
        mv();
        step++;

    }while(step<=k);
    return -1;
}
int solve2()
{
    int step=0;
    do
    {
        if (eq()) return step;
        rb();
        step++;

    }while(step<=k);
    return -1;
}
int main()
{
    cin>>n>>k;
    for (int i=1;i<=n;i++)
        cin>>q[i],p[i]=i;
    for (int i=1;i<=n;i++)
        cin>>s[i];
    int x1=solve1();
    for (int i=1;i<=n;i++)
        p[i]=i;
    int x2=solve2();
    if (x1==-1 || (k-x1)%2!=0 || ((k-x1)%2==0 && k!=x1 && (max(x1,x2)<=1 && min(x1,x2)!=-1)))
    {
        if (x2==-1 || (k-x2)%2!=0 || ((k-x2)%2==0 && k!=x2 && (max(x1,x2)<=1 && min(x1,x2)!=-1)))
            cout<<"NO\n";
        else
            cout<<"YES\n";
    }
    else
        cout<<"YES\n";
}