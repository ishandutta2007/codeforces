//#include <cstdlib>
#include<iostream>
#include<cstring>
#include<algorithm>
#include <map>
#include<vector>
using namespace std;
struct node
{
    int val,id;
};
bool operator<(node a, node b)
{
    return a.val<b.val;
}
int a[1000000];

node b[1000000];
int ans[1000000];
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    for (int i=0;i<m;i++)cin>>b[i].val,b[i].id=i;
    sort(b,b+m);
    int l=0;
    for (int i=0;i<m;i++)
    {
        while(l<n && a[l]<=b[i].val)
            l++;
        ans[b[i].id]=l;
    }
    for (int i=0;i<m;i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}