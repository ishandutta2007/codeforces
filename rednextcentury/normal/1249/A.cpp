#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool vis[10000];
int a[10000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for (int i=0;i<n;i++)
        {
            cin>>a[i];
            vis[i]=0;
        }
        sort(a,a+n);
        int ret=0;
        for (int i=0;i<n;i++) {
            if (!vis[i]){
                ret++;
                vis[i]=1;
                int lst = a[i];
                for (int j=i+1;j<n;j++) {
                    if (a[j]-lst>1 && !vis[j])vis[j]=1,lst=a[j];
                }
            }
        }
        cout<<ret<<endl;
    }
}