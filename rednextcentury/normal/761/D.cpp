#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
struct node
{
    int a;
    int b;
    int p;
    int c;
    int id;
};
bool c1(node a,node b)
{
    return a.id<b.id;
}
bool c2(node a,node b)
{
    return a.p<b.p;
}
node a[1000000];
int main()
{
    fast
    int n,l,r;
    cin>>n>>l>>r;
    for (int i=1;i<=n;i++)
        cin>>a[i].a;
    for (int i=1;i<=n;i++)
        cin>>a[i].p,a[i].id=i;
    bool no=0;
    sort(a+1,a+n+1,c2);
    a[1].b=l;
    a[1].c=a[1].b-a[1].a;
    for (int i=2;i<=n;i++)
    {
        a[i].b=a[i-1].c+a[i].a+1;
        if (a[i].b>r)no=1;
        else if (a[i].b<l)
            a[i].b=l;
        a[i].c=a[i].b-a[i].a;
    }
    if (no)cout<<-1<<endl;
    else
    {
        sort(a+1,a+n+1,c1);
        for (int i=1;i<=n;i++)
            cout<<a[i].b<<' ';
        cout<<endl;
    }
}