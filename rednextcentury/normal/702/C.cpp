#include<bits/stdc++.h>
using namespace std;
map<int,int> mp;
int a[1000000];
int b[1000000];
int n,m;
int check()
{
    int cur=0;
    int ans=0;
    for (int i=0;i<n;i++)
    {
        while(cur+1<m && abs(a[i]-b[cur])>=abs(a[i]-b[cur+1]))
            cur++;
        ans=max(ans,abs(a[i]-b[cur]));
    }
    return ans;
}
int main()
{
    cin>>n>>m;
    for (int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for (int i=0;i<m;i++)
        scanf("%d",&b[i]);
    int ans=2000000000;
    int l=0,r=2000000000;
    cout<<check()<<endl;
}