#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int num[1000000];
int ret[1000000];
int go[1000000];
int b[1000000];
int main()
{
    int n;
    cin>>n;
    bool no=0;
    int x=0;
    int last=-1,cur=0;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
        if (++num[a[i]]==1)
            x++;
    }
    for (int i=1;i<=n;i++)
        if (a[a[i]]!=a[i])
            no=1;
    if(no)
        cout<<-1<<endl;
    else
    {
        cout<<x<<endl;
        sort(a+1,a+n+1);
        int last=-1,cur=0;
        for (int i=1;i<=n;i++)
        {
            if (a[i]==last)go[a[i]]=cur;
            else last=a[i],cur++,go[a[i]]=cur;
            ret[cur]=a[i];
        }
        for (int i=1;i<=n;i++)
            cout<<go[b[i]]<<' ';
        cout<<endl;
        for (int i=1;i<=x;i++)
            cout<<ret[i]<<' ';
        cout<<endl;
    }
}