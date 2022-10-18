#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
const int N = 2e5 + 11;
int a[N],use[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    int ans=0;
    for (int i=1; i<=n; i++)
    {
        int k=a[i];
        if (use[k]==0)
        {
            ans++;
            int kol=0;
            for (int j=1; j<=n; j++)
                if (use[j]>0) kol++;
            if (kol==m)
            {
                int kek=0;use[0]=0;
                for (int j=1; j<=n; j++)
                    if (use[j]!=0&&use[j]>use[kek]) kek=j;
                use[kek]=0;
            }
        }
        use[k]=0;
        for (int j=i+1; j<=n; j++)
            if (a[j]==k) {use[k]=j; break;}
    }
    cout<<ans<<endl;
}