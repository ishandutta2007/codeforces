#include<bits/stdc++.h> 
using namespace std; 
#define ll long long int
#define v vector<ll>
#define vv vector<v>
#define p pair<ll,ll>
#define MAX 15000001
#define fi first
#define se second
#define pp pair<p,int>
#define pi pair<int,p>
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k;
    cin>>n>>k;
    v arr(n+1);
    int sum=0;
    for (int i=1; i<=n; i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    if (sum%k!=0)
    {
        cout<<"No"<<endl;
        return 0;
    }
    v ans(1,0);
    ll sum2=0;
    for (int i=1; i<=n; i++)
    {
        sum2+=arr[i];
        if (sum2==sum/k)
        {
            ans.push_back(i);
            sum2=0;
        }   
        if (sum2>sum/k)
        {
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    for (int i=1; i<=k; i++)
    {
        cout<<ans[i]-ans[i-1]<<" ";
    }
    return 0;
}