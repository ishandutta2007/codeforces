#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long

const int N = 2e5 + 11;

int a[N],b[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<=n; i++)
        cin>>b[i];
    for (int x=1; x<=1000; x++)
    {
        int s1=0,s2=0;
        for (int i=1; i<=n; i++)
            if (a[i]==1&&b[i]==0) s1+=x; else
            if (a[i]==0&&b[i]==1) s2+=1;
        if (s1>s2)
        {
            cout<<x;
            return 0;
        }
    }
    cout<<-1;
}