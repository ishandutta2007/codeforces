#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool vis[1000000];
int a[1000000];
int ret[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for (int i=1;i<=n;i++)
        {
            cin>>a[i];
            vis[i]=0;
        }
        for (int i=1;i<=n;i++) {
            if (vis[i])continue;
            int sz=0;
            vector<int> vec;
            int v = i;
            while(1){
                sz++;
                vec.push_back(v);
                v=a[v];
                if (v==i)break;
            }
            for (auto x:vec)ret[x]=sz;
        }
        for (int i=1;i<=n;i++)cout<<ret[i]<<' ';
        cout<<endl;
    }
}