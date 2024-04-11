#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back

const int N = 2000 + 11;

bool use[N][N];
char a[N][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    int l,r;
    cin>>l>>r;
    int x,y;
    cin>>x>>y;
    deque<int> l1,r1,x1,y1;
    l1.push_back(l);
    r1.push_back(r);
    x1.push_back(x);
    y1.push_back(y);
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
    cin>>a[i][j];
    use[l][r]=1;
    int ans=0;
    while (l1.size()>0)
    {
        int l=l1.front(),r=r1.front(),x=x1.front(),y=y1.front();
        l1.pop_front();
        r1.pop_front();
        x1.pop_front();
        y1.pop_front();
        ans++;
        //cout<<l<<" "<<r<<endl;
        if (a[l-1][r]=='.'&&use[l-1][r]==0)
        {
            use[l-1][r]=1;
            l1.push_front(l-1);
            r1.push_front(r);
            x1.push_front(x);
            y1.push_front(y);
        }
        if (a[l+1][r]=='.'&&use[l+1][r]==0)
        {
            use[l+1][r]=1;
            l1.push_front(l+1);
            r1.push_front(r);
            x1.push_front(x);
            y1.push_front(y);
        }
        if (a[l][r-1]=='.'&&use[l][r-1]==0&&x>0)
        {
            use[l][r-1]=1;
            l1.push_back(l);
            r1.push_back(r-1);
            x1.push_back(x-1);
            y1.push_back(y);
        }
        if (a[l][r+1]=='.'&&use[l][r+1]==0&&y>0)
        {
            use[l][r+1]=1;
            l1.push_back(l);
            r1.push_back(r+1);
            x1.push_back(x);
            y1.push_back(y-1);
        }
    }
    cout<<ans<<endl;
}