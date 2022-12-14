#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<vector<int> >vvi;
typedef vector<int> vi;
int n,s;
ll a[100001];
ll b[100001];
ll outRes=0,temp;
bool ok(ll mid)
{
    ll res=0;
    for(int i=0;i<n;i++)
    {
        b[i]=a[i]+(i+1)*mid;
    }
    sort(b,b+n);
    for(int i=0;i<mid;i++)
    {
        res+=b[i];
        if(res>s)
            return false;
    }
    temp=res;
    return res<=s;
}
int main()
{
    ios::sync_with_stdio(0);
    cin>>n>>s;
    ll Min=1e6;
    for(int i=0;i<n;i++){
        cin>>a[i];
        Min=min(Min,a[i]);
    }
    if(s<Min+1)
    {
        cout<<"0 0"<<endl;
        return 0;
    }
    ll l=0,h=n;
    ll best=0;
    while(l<=h)
    {
        ll mid=(l+h)/2;
        if(ok(mid))
        {
            if(mid>best)
            {
                best=mid;
                outRes=temp;
            }
            l=mid+1;
        }
        else
            h=mid-1;
    }
    cout<<best<<" "<<outRes<<endl;
    return 0;
}