#include<iostream>
using namespace std;
int from[1000000];
int to[1000000];
int after[1000000];
int len[1000000];
int main()
{
    int n,p;
    cin>>n>>p;
    for (int i=0;i<=n;i++)
        after[i]=-1;
    for (int i=0;i<p;i++)
    {
        int a,b,k;
        cin>>a>>b>>k;
        after[a]=b;
        from[a]++;
        to[b]++;
        len[a]=k;
    }
    int num=0;
    for (int i=1;i<=n;i++)
    {
        if (from[i]>0 && to[i]==0)
            num++;
    }
    cout<<num<<endl;
    for (int i=1;i<=n;i++)
    {
        if (from[i]>0 && to[i]==0)
        {
            int v=i;
            int mn=1000000000;
            while(1)
            {
                if (after[v]==-1)
                    break;
                mn=min(mn,len[v]);
                v=after[v];
            }
            cout<<i<<" "<<v<<" "<<mn<<endl;
        }
    }
}