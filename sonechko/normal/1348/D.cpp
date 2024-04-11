#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 4e5 + 11;

int a[N];

int up(int n, int k)
{
    int sum=k+1,x=1;
    for (int j=1; j<=k; j++)
    {
        int kol=n-sum;
        int t=min(x,kol/(k-j+1));
        a[j]=t;
        sum+=t*(k-j+1);
        x+=t;
    }
    if (sum==n)
    {
        cout<<k<<"\n";
        for (int j=1; j<=k; j++)
            cout<<a[j]<<" ";
        cout<<"\n";
        return 1;
    }
    return 0;
}

void up()
{
    int n;
    cin>>n;
    for (int k=1; k<=100; k++)
        if (up(n,k)) return;
    ///cout<<"NO\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        up();
        ///cout<<endl;
    }
}
/**
k sum
p

-> (k-p)+p/2 sum+(k-p)+p/2

x -> x..2x

T
1 * T



**/