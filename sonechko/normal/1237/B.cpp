#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 3e5 + 11;

int a[N],b[N],use[N];
int pos[N],cc[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        pos[a[i]]=i;
    }
    for (int i=1; i<=n; i++)
        cin>>b[i];
    int ans=0;
    int last=n+1;
    for (int i=n; i>=1; i--)
    {
        int p=pos[b[i]];
        use[b[i]]=1;
        while (last>p)
        {
            last--;
            if (use[a[last]]==0&&cc[a[last]]==0)
                {ans++; cc[a[last]]=1;}
        }
        use[b[i]]=1;
    }
    cout<<ans;
}