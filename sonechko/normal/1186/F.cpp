#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;

vector<int> v[N],d[N];
bool use[N];
int kol[N],a[N],b[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    srand(time(NULL));
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=m; i++)
    {
        int l,r;
        cin>>l>>r;
        a[i]=l;
        b[i]=r;
        kol[l]++;
        kol[r]++;
    }
    for (int i=1; i<=n; i++)
        kol[i]=kol[i]-(kol[i]+1)/2;
    int t=m-min(m,(n+m+1)/2);
    for (int i=1; i<=m; i++)
        d[min(kol[a[i]],kol[b[i]])].pb(i);
    int ps=0;
    for (int i=m; i>=1; i--)
    {
        for (int p=0; p<d[i].size(); p++)
        {
            if (ps==t) break;
            int num=d[i][p];
            if (min(kol[a[num]],kol[b[num]])==i)
            {
                use[num]=1;
                ps++;
                kol[a[num]]--;
                kol[b[num]]--;
            } else
            {
                int c=min(kol[a[num]],kol[b[num]]);
                if (c>0&&rand()%5==0)
                {
                    use[num]=1;
                ps++;
                kol[a[num]]--;
                kol[b[num]]--;
                } else
                if (c>0) d[c].pb(num);
            }
        }
    }
    cout<<m-t<<"\n";
    for (int i=1; i<=m; i++)
    if (use[i]==0) cout<<a[i]<<" "<<b[i]<<"\n";
}