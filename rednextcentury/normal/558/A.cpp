#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
struct tree
{
    int x;
    int v;
};
bool operator<(tree a,tree b)
{
    if (a.x<0)
    {
        return a.x>b.x;
    }
    return a.x<b.x;
}
tree a[100000];
tree b[100000];
int main()
{
    int n;
    cin>>n;
    int tot1=0;
    int tot2=0;
    for (int i=0;i<n;i++)
    {
        int x,v;
        cin>>x>>v;
        if (x<0)
        {
            a[tot1].x=x;
            a[tot1].v=v;
            tot1++;
        }
        else
        {
            b[tot2].x=x;
            b[tot2].v=v;
            tot2++;
        }
    }
    sort(a,a+tot1);
    sort(b,b+tot2);
    int ans=0;
    if (tot1<tot2)
    {
        for (int i=0;i<tot1;i++)
            ans+=a[i].v+b[i].v;
        ans+=b[tot1].v;
    }
    else
    {
        for (int i=0;i<tot2;i++)
            ans+=a[i].v+b[i].v;
        if (tot2<tot1)
        ans+=a[tot2].v;
    }
    cout<<ans<<endl;
}