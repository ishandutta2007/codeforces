#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back
#define y1 dhnfg
#define ld long double

const int N = 1e6 + 11;

int a[N];
int use[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    for (int i=0; i<256; i++)
        use[i]=-1;
    for (int i=1; i<=n; i++)
    {
        int l;
        cin>>l;
        if (use[l]!=-1) cout<<use[l]<<" "; else
        {
            int r=l;
            while (r!=0&&use[r-1]==-1&&l-r+1<k)
                r--;
            int p=r;
            if (r!=0&&l-use[r-1]<k) p=use[r-1];
            for (int j=r; j<=l; j++)
                if (use[j]==-1) use[j]=p; else break;
            cout<<use[l]<<" ";
        }
    }
    cout<<endl;
}