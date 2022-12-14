

    #include <bits/stdc++.h>
    #define ll long long
    #define ld long double
    #define pb push_back
    #define pii pair <int, int>
    #define fr first
    #define se second
    #define all(v) v.begin(), v.end()
    #define loop(n) for(int i = 0; i < n; i++)
    #define loopy(n) for(int j = 0; j < n; j++)
    using namespace std;
     
    const int N = 1e5 + 10;
    ll remov[N];
     
    int main()
    {
        ll n, m, k;
        cin>>n>>m>>k;
        for(ll i = 1; i <= m; i++)
            cin>>remov[i];
     
        ll removed = 0;
        ll i = 1, res = 0;
        while(i <= m)
        {
            ll prev = i;
            ll x = ((remov[i]-removed) / k)-((remov[i]-removed)%k==0);
     
            while( i <= m && ((remov[i]-removed) / k)-((remov[i]-removed)%k==0) == x)
                i++;
     
            res++;
            removed += i-prev;
        }
     
        cout<<res;
     
     
        return 0;
    }