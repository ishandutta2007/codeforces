#include <bits/stdc++.h>
using namespace std;
long long root;
long long n;
int mv[1000000];
int t=0;
struct node
{
    long long l,r;
    long long v;
    void goLeft()
    {
        if (l<r){
        r=v-1;
        v=(l+r)/2;
        mv[t++]=1;
        }
    }
    void goRight()
    {
        if (l<r){
        l=v+1;
        v=(l+r)/2;
        mv[t++]=0;
        }
    }
    void goUp()
    {
        if (v!=root)
        {
            long long sz=(r-l+1);
            if (mv[t-1]==0)
            {
                v=l-1;
                l=v-sz;
                r=v+sz;
            }
            else
            {
                v=r+1;
                l=v-sz,r=v+sz;
            }
            t--;
        }
    }
};
node getNode(long long v)
{
    node c;
    c.l=1,c.r=n;
    c.v=(c.l+c.r)/2;
    while(v!=c.v)
    {
        if (c.v<v)
            c.goRight();
        else
            c.goLeft();
    }
    return c;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    root=(n+1)/2;
    int q;
    cin>>q;
    while(q--)
    {
        long long s;
        cin>>s;
        string x;
        cin>>x;
        t=1;
        node c=getNode(s);

        for (int i=0;i<x.size();i++)
        {
            if (x[i]=='U')c.goUp();
            else if (x[i]=='L')c.goLeft();
            else c.goRight();
        }
        cout<<c.v<<endl;
    }
}