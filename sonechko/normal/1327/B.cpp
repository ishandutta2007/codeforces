#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

int use[N];
int d[N];

void up()
{
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        use[i]=0;
    int t=0;
    for (int i=1; i<=n; i++)
    {
        int k;
        cin>>k;
        int p=0;
        for (int j=1; j<=k; j++)
        {
            int l;
            cin>>l;
            if (p==0&&use[l]==0) {use[l]=1; p=1;}
        }
        if (p==0) {t=i;}
    }
    if (t==0) cout<<"OPTIMAL\n"; else
    {
        cout<<"IMPROVE\n";
        cout<<t<<" ";
        for (int i=1; i<=n; i++)
            if (use[i]==0) {cout<<i<<" "; break;}
        cout<<"\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--) up();
}