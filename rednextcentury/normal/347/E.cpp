#include <bits/stdc++.h>
using namespace std;
long long a[1000002];
map<int,int> mp;
int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i];
    long long A,B;
    cin>>A>>B;
    int s=0;
    for(int i=0;i<n;i++)
    {
        if (++mp[a[i]]>1)
        {
            swap(a[i],a[s]);
            s++;
        }
    }
    int ret=0;
    while(A!=B)
    {
        long long mx=1;
        for (int i=s;i<n;i++)
        {
            if (a[i]>A || A-(A%a[i])<B)
            {
                swap(a[i],a[s]);
                s++;
            }
            else
                mx=max(mx,A%a[i]);
        }
        A-=mx;
        ret++;
    }
    cout<<ret<<endl;
}