# include <iostream>
# include <vector>
# include <stdio.h>
#include <limits.h>
#include <stack>
#include <algorithm>
using namespace std;
int can[10000001];
int a[1000001];
pair<int,int> b[1000001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=0;i<=10000000;i++)
        can[i]=k;
    for (int i=0;i<n;i++)
        cin>>a[i],can[a[i]]--;
    for (int i=0;i<m;i++)
        cin>>b[i].first,b[i].second=i+1;
    sort(b,b+m);
    for (int i=10000000;i>0;i--)
        if (can[i]<0)
            can[i-1]+=can[i],can[i]=0;
    if (can[0]<0)
    {
        cout<<-1<<endl;
return 0;
    }
    int cur=0;
    vector<int> vec;
    for (int i=0;i<m;i++)
    {
        while(i<m && b[i].first<cur)
            i++;
        while(can[cur]==0 && cur<=b[i].first)
            cur++;
        if (cur<=b[i].first)
            can[cur]--,vec.push_back(b[i].second);
    }
    cout<<vec.size()<<endl;
    for (int i=0;i<vec.size();i++)
        cout<<vec[i]<<' ';
    cout<<endl;
}