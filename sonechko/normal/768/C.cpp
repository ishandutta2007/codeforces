#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 11;
const long long MOD = 1e9 + 7;
#define mod %MOD
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ss second
#define ff first
#define ll long long
#define mp make_pair
#define endl "\n"
#define pb push_back
#define ld long double
int a[N],b[N],c[N];
vector<int> v;
int main()
{
    sync;
    int n,k,x;
    cin>>n>>k>>x;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for (int i=1; i<=k; i++)
    {
        int kol1=b[1],kol2=b[n];
        for (int ij=1; ij<=n; ij++)
        b[ij]=a[ij];
        for (int j=1; j<=n; j+=2)
            a[j]=(a[j]^x);
        sort(a+1,a+n+1);
        int k=1;
        if (a[1]==b[1]&&a[n]==b[n]&&a[1]==kol1&&a[n]==kol2) k=0;
        if (k==0)
        {
            if ((k-i)%2==0)
            {
                cout<<a[n]<<" "<<a[1]<<endl;
            } else
            {
                cout<<b[n]<<" "<<b[1]<<endl;
            }
            return 0;
        }
    }
    cout<<a[n]<<" "<<a[1]<<endl;
}