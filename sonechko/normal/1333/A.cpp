#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

void up()
{
    int n,m;
    cin>>n>>m;
    if (n%2==1&&m%2==1)
    {
        for (int i=1; i<=n; i++)
        {
            for (int j=1; j<=m; j++)
            if ((i+j)%2==0) cout<<"B"; else cout<<"W";
            cout<<"\n";
        }
        return;
    } else
    {
        for (int i=1; i<=n; i++)
        {
            for (int j=1; j<=m; j++)
            if ((i+j)%2==1||i+j==2) cout<<"B"; else cout<<"W";
            cout<<"\n";
        }
        return;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--) up();
}
/**

2 2
BBW
BWB


**/