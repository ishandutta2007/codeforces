#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const long long MOD = 1e9 + 7;
#define mod %MOD
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ss second
#define ff first
#define ll long long
#define mp make_pair
#define endl "\n"
#define pb push_back
#define y1 ijdj
#define next lzk
#define ld long double
string a[N],b[N];
int use1[N],use2[N];
int main()
{
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #else
    #endif
    sync;
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<=m; i++)
        {
            cin>>b[i];
            for (int j=1; j<=n; j++)
                if (a[j]==b[i])
            {
                use1[j]=i;
                use2[i]=j;
            }
        }
    for (int ij=1; ij<=n+m+2; ij++)
    {
        if (ij%2==1)
        {
            int k=0;
            for (int i=1; i<=n; i++)
                if (use1[i]>0)
            {
                use2[use1[i]]=-1;
                use1[i]=-1;
                k=1;
                break;
            }
            if (k==0)
            {
                int p=0;
                for (int i=1; i<=n; i++)
                    if (use1[i]==0)
                {
                    use1[i]=-1;
                    p=1;
                    break;
                }
                if (p==0) {cout<<"NO"<<endl; return 0;}
            }
        } else
        {
            int k=0;
            for (int i=1; i<=m; i++)
                if (use2[i]>0)
            {
                use1[use2[i]]=-1;
                use2[i]=-1;
                k=1;
                break;
            }
            if (k==0)
            {
                int p=0;
                for (int i=1; i<=m; i++)
                    if (use2[i]==0)
                {
                    use2[i]=-1;
                    p=1;
                    break;
                }
                if (p==0) {cout<<"YES"<<endl; return 0;}
            }
        }
    }
}