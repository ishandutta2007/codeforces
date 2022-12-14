#include <iostream>
# include <cstdlib>
# include <algorithm>
#include<cstdio>
# include <vector>
#include <cmath>
#include <map>
#include<set>
#include <stack>
using namespace std;
struct inst
{
    int idx;
    int tim;
};
inst a[10000];
int ans[1000];
bool comp(inst a1,inst a2)
{
    return a1.tim<a2.tim;
}
int main()
{
    int n,k;
    int tot=0;
    cin>>n>>k;
    for (int i=0;i<n;i++)
        cin>>a[i].tim,a[i].idx=i+1;
    sort(a,a+n,comp);
    for (int i=0;i<n;i++)
    {
        if (a[i].tim>k)
            break;
        k-=a[i].tim;
        ans[tot++]=a[i].idx;
    }
    cout<<tot<<endl;
    for (int i=0;i<tot;i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}