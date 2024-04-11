#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const long long MOD = 1e9 + 7;
#define mod %MOD
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ss second
#define ff first
#define ll long long
#define mp make_pair
#define endl "\n"
#define pb push_back
#define y1 ijdj
#define next lzk
#define tab difjke
int a[N],b[N];
int main()
{
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin>>n;
    int k1=0,k2=0;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i]>>b[i];
        if (b[i]==2) {k1=1;}
        if (b[i]==1) {k2=1;}
    }
    if (k1==0) {cout<<"Infinity"<<endl; return 0;}
    if (k2==0)
    {
        int sum=0,ans=1899;
        for (int i=1; i<n; i++)
        {
            sum+=a[i];
            if (sum>0) ans=min(ans,1899-sum);
        }
        sum+=a[n];
        cout<<ans+sum<<endl;
        return 0;
    }
    for (int i=1; i<n; i++)
    if (a[i]>=0&&b[i]==1&&b[i+1]==2)
    {
        cout<<"Impossible"<<endl;
        return 0;
    } else
    if (a[i]<=0&&b[i]==2&&b[i+1]==1)
    {
        cout<<"Impossible"<<endl;
        return 0;
    }
    int l=0,r=0,sum=0;
    for (int i=1; i<n; i++)
        {
            if (b[i]==1&&b[i+1]==2)
    {
        r=1899+abs(a[i])+sum;
        l=1900+sum;
    }
    if (b[i]==2&&b[i+1]==1)
    {
        l=1900-a[i]+sum;
        r=1899+sum;
    }
    sum+=-a[i];
        }
    int ans=INT_MIN;
    for (int k=l; k<=r; k++)
    {
        int p=k;
        for (int i=1; i<=n; i++)
        {
            if (p+a[i]>=1900&&b[i+1]==2)
            {
                p=INT_MIN;
                break;
            }
            if (p+a[i]<1900&&b[i+1]==1)
            {
                p=INT_MIN;
                break;
            }
            p+=a[i];
        }
        if (k>=1900&&b[1]==2) p=INT_MIN;
        if (k<1900 &&b[1]==1) p=INT_MIN;
        if (p>ans) {ans=p;}
    }
    #ifdef LOCAL
    cout<<"!"<<endl;
    #endif // LOCAL
    if (ans==INT_MIN) cout<<"Impossible"<<endl;
    else cout<<ans<<endl;
}