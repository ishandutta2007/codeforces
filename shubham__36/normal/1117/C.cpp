#include<bits/stdc++.h> 
using namespace std; 
#define ll long long int
#define v vector<ll>
#define vv vector<v>
#define p pair<ll,ll>
#define MAX 15000001
ll n;
ll LIM=1e5+10;
vector<p> pos(LIM);
ll a,b;
ll a1,b1;
bool check(ll mid)
{
    ll num=mid/n;
    ll x1=a+num*pos[n].first;
    ll y1=b+num*pos[n].second;
    //cout<<x1<<" "<<y1<<" "<<n<<" "<<pos[n].second<<endl;
    ll rem=mid%n;
    x1+=pos[rem].first;
    y1+=pos[rem].second;
    //cout<<x1<<" "<<y1<<" "<<pos[2].second<<" "<<rem<<endl;
    ll d2=abs(x1-a1)+abs(y1-b1);
    if (d2<=mid)
        return true;
    else
        return false;
}
int main() 
{ 
    cin>>a>>b;
    cin>>a1>>b1;
    cin>>n; 
    string s;
    cin>>s;
    //cout<<n<<endl;
    ll init=abs(a-a1)+abs(b-b1);
    ll x=0;
    ll y=0;
    for (int i=1; i<=n; i++)
    {
        if (s[i-1]=='U')
            y++;
        if (s[i-1]=='D')
            y--;
        if (s[i-1]=='L')
            x--;
        if (s[i-1]=='R')
            x++;
        pos[i]=p(x,y);
    }
    ll d=abs(a+pos[n].first-a1)+abs(b+pos[n].second-b1);
    if (d-init>=n)
    {
        cout<<-1<<endl;
    }
    else
    {
        ll l=0;
        ll r=1e18;
        while (true)
        {
            //cout<<l<<" "<<r<<endl;
            ll mid=(l+r)/2;
            // ll num=mid/n;
            // ll x1=a+num*pos[n].first;
            // ll y1=b+num*pos[n].second;
            // ll rem=mid%n;
            // x1+=pos[rem].first;
            // y1+=pos[rem].second;
            // ll d2=abs(x1-a1)+abs(y1-b1);
            if (check(mid))
            {
                r=mid;
            }
            else
            {
                l=mid+1;
            }
            if (l==r)
                break;
        }
        if (l>=1e16)
        cout<<-1<<endl;
        else
    cout<<l<<endl;
    }
    return 0; 
}