#include<iostream>
#include<vector>
#include<algorithm>

#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

using namespace std;

const int N = 200007;

int n;
int c[N],a[N];

int res=0;

int firstVisit[N];
bool b[N];
vector<int> visit;

void solve(int u)
{
    //cout<<u<<" "<<res<<endl;

    firstVisit[u]=visit.size();
    visit.push_back(u);

    if(u==a[u])
    {
        b[u]=1;
        res+=c[u];
        return;
    }

    if(b[a[u]])
    {
        b[u]=1;
        return;
    }

    int mini=10001;

    if(firstVisit[a[u]]!=0)
    {
        for(int i=firstVisit[a[u]];i<=firstVisit[u];i++)
            mini=min(c[visit[i]],mini);

        res+=mini;
        b[u]=1;
        return;
    }

    solve(a[u]);

    b[u]=1;
}

int main ()
{
    int i;

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;

    for(i=1;i<=n;i++)
        cin>>c[i];

    for(i=1;i<=n;i++)
        cin>>a[i];

    visit.push_back(0);

    for(i=1;i<=n;i++)
    {
        if(!b[i])
            solve(i);
    }

    cout<<res<<"\n";

    return 0;
}