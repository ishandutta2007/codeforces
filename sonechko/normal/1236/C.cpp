#include<bits/stdc++.h>
using namespace std;

#define pb push_back

const int N = 1e5 + 11;

vector<int> v[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        int l=(i-1)*n+1;
        int r=i*n;
        if (i%2==1)
        {
            for (int j=1; j<=n; j++)
                v[j].pb(l+j-1);
        } else
        {
            for (int j=1; j<=n; j++)
                v[j].pb(r-j+1);
        }
    }
    for (int i=1; i<=n; i++)
    {
        for (int j=0; j<v[i].size(); j++)
            cout<<v[i][j]<<" ";
        cout<<"\n";
    }
}
/**
1 6 7
2 5 8
3 4 9
**/