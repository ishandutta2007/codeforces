#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e5 + 5;

ll read()
{
    char ch=getchar();
    ll x=0,f=1;
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
    return x*f;
}

ll n, w, a[maxn];
map<ll, ll> mp;

void init()
{
    for (int i = 0; i <= 20; i++) mp[(1 << i)] = i;
}


void solve()
{
    n = read(), w = read();
    ll cnt[200];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; i++) a[i] = read(), cnt[mp[a[i]]]++;
    ll ans = 0;
    while(n)
    {
        ll _w = w;
        for (int i = 20; i >= 0; i--)
        {
            if (_w >= (1 << i) && cnt[i]) 
            {
                ll t = min(_w / (1 << i), cnt[i]);
                _w -= (1 << i) * t; 
                cnt[i]-=t; 
                n-=t;
            }
        }
        //cout << _w << endl;
        ans++;
    }
    cout << ans << "\n";
}

int main()
{
    init();
    int t;cin>>t;
    while(t--){
        solve();
    }
}