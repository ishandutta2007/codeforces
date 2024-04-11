# include<bits/stdc++.h>
using namespace std;
bool vis[1000];
vector<int> vec,vec2;
int a[1000000];
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        a[x]=i+1;
    }
    long long ans=0;
    for (int i=2;i<=n;i++)
    {
        ans+=abs(a[i]-a[i-1]);
    }
    cout<<ans<<endl;
}