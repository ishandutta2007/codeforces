
# include <iostream>
# include <string>
# include <algorithm>
# include <map>
#include<stdio.h>
# include <vector>
#define EPS 1e-9
using namespace std;
struct le
{
    int l,r,idx;
};
bool operator<(le a,le b)
{
    return a.l<b.l;
}
le a[1000000];
vector<int> ret;
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++) cin>>a[i].l>>a[i].r,a[i].idx=i+1;
    sort(a,a+n);
    for (int i=0;i<n;i++)
    {
        bool p=1;
        for (int j=0;j<n-1;j++)
        {
            if (i==j) continue;
            if (j+1==i)
            {
                if (j+2<n && a[j].r>a[j+2].l)
                    p=0;
            }
            else if (a[j].r>a[j+1].l)
                p=0;
        }
        if (p)
            ret.push_back(a[i].idx);
    }
    cout<<ret.size()<<endl;
    sort(ret.begin(),ret.end());
    for (int i=0;i<ret.size();i++)
    {
        cout<<ret[i]<<" ";

    }
    cout<<endl;
}