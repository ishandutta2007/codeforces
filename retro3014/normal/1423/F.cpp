#include<iostream>
#include<vector>
#include<algorithm>
#define ep emplace
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef pair<ll,ll>pl;
const int inf=1e9+7;
const ll INF=1e18;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    cin>>n>>k;
    ll sum1=0;
    ll sum2=0;
    ll sum3=(ll)n*(n-1)/2;
    for(int i=0;i<k;i++)
    {
        int a,b;
        cin>>a>>b;
        a%=n;
        sum1+=b;
        sum2+=(ll)a*b;
    }
    int ans=0;
    if(sum1<n)
        ans=1;
    else if(sum1>n)
        ans=-1;
    else if(sum2%n==sum3%n)
        ans=1;
    else
        ans=-1;
    cout<<ans<<endl;
    return 0;
}