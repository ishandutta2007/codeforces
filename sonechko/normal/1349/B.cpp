#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 4e5 + 11;

int a[N],s1[N],s2[N],b[N];

void up()
{
    int n,k;
    cin>>n>>k;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    int c=0;
    for (int i=1; i<=n; i++)
    {
        if (a[i]==k&&i>1&&a[i-1]>a[i])
        {
            cout<<"yes\n";
            return;
        }
        if (a[i]==k&&i>1&&a[i]==a[i-1])
        {
            cout<<"yes\n";
            return;
        }
        if (a[i]==k&&i<n&&a[i+1]>a[i])
        {
            cout<<"yes\n";
            return;
        }
        if (a[i]==k) c=1;
    }
    if (n==1&&c==1)
    {
        cout<<"yes\n";
        return;
    }
    for (int i=2; i<=n; i++)
    {
        if (a[i]>=k&&a[i-1]>=k&&c==1)
        {
            cout<<"yes\n";
            return;
        }
        if (i>1&&a[i]>=k&&a[i-2]>=k&&c==1)
        {
            cout<<"yes\n";
            return;
        }
    }
    cout<<"no\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--) up();
}