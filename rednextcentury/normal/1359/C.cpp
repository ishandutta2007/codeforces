#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ans = 0;
long double best = 1e18;
long double eps = 0;
        ll h,c,t;
void upd(long double val, ll num){
    val = fabs(val - t);
    if (fabs(val - best) <= 1e-12) ans=min(ans,num);
    else if (val<best){
        best = val;
        ans = num;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        best=1e18;
        ans=0;
        cin>>h>>c>>t;
        upd(h, 1);
        upd((h+c)/2.0, 2);
        long long l=0,r=1e12;
        ll ret=0;
        while(l<=r){
            ll mid = (l+r)/2;
            long double cur = 2*mid+1;
            long double temp = (mid*c+(mid+1)*h)/cur;
            if (temp < t) ret = mid, r=mid-1;
            else l=mid+1;
        }
        long double cur = 2*ret+1;
        long double temp = (ret*c+(ret+1)*h)/cur;
        upd(temp, ret*2+1);
        if (ret)ret--;
        cur = 2*ret+1;
        temp = (ret*c+(ret+1)*h)/cur;
        upd(temp, ret*2+1);
        cout<<ans<<endl;
    }
}