#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 11;

bool use[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int l,r;
    cin>>l>>r;
    for (int i=1; i<n; i++)
    {
        int l,r;
        cin>>l>>r;
        for (int j=l; j<r; j++)
            use[j]=1;
    }
    int ans=0;
    for (int i=l; i<r; i++)
        if (use[i]==0) ans++;
    cout<<ans<<endl;
}