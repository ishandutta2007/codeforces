# include <iostream>
# include <algorithm>
#include <set>
#include <queue>
#include <string>
using namespace std;
struct node
{
    int idx;
    string s1;
    string s2;
};
bool operator<(node a,node b)
{
    return a.idx<b.idx;
}
string ans[1000000];
node a[1000000];
int main()
{
    int n;
    cin>>n;
    string y,z;
    for (int i=0;i<n;i++)
    {
        cin>>y>>z;
        if (y<z)
            a[i].s1=y,a[i].s2=z;
        else
            a[i].s1=z,a[i].s2=y;
    }
    for (int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        a[k-1].idx=i;;
    }
    sort(a,a+n);
    ans[0]=a[0].s1;
    for (int i=1;i<n;i++)
    {
        if (a[i].s1>ans[i-1])
            ans[i]=a[i].s1;
        else if (a[i].s2>ans[i-1])
            ans[i]=a[i].s2;
        else
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
}