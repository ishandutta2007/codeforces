#include<iostream>
#include<map>
#include<math.h>
#include<stdio.h>
#include<cstring>
#include<string.h>
#include<deque>
#include<algorithm>
using namespace std;
typedef __int64 ll;
const int maxn=100005;
ll res=1,sum[maxn],a[maxn];
deque<int> d;
int main()
{
    int n;cin>>n;
    for(int i=1;i<=n-1;i++)
    {
        cin>>a[i];
    }
    sum[n-1]=1;d.push_front(n-1);
    for(int i=n-2;i>=1;i--)
    {
        int next=upper_bound(d.begin(),d.end(),a[i])-d.begin()-1;
        sum[i]=sum[d[next]]+(ll)(n-i)-(ll)((ll)a[i]-d[next]);
        res+=sum[i];
        while(!d.empty()&&a[d.front()]<=a[i]) d.pop_front();
        d.push_front(i);
    }
    cout<<res<<endl;
    return 0;
}