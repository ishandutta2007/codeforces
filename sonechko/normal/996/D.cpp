#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long

const int N = 1e6 + 11;

int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n*2; i++)
        cin>>a[i];
    int pos=1,ans=0;
    while (pos<n*2)
    {
        if (a[pos]==a[pos+1]) pos+=2; else
        {
            for (int d=pos+1; d<=n*2; d++)
                if (a[d]==a[pos])
            {
                swap(a[d],a[d-1]);
                ans++;
                break;
            }
        }
    }
    cout<<ans<<endl;
}