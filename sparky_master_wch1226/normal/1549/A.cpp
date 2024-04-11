#include<bits/stdc++.h>
#define ff              first
#define ss              second
#define ld              long double
#define ll              long long int
#define mod             1000000007
#define vll             vector<ll>
#define pll             pair<ll, ll>
#define uom             unordered_map
#define uos             unordered_set
#define mxh             priority_queue<ll>
#define ull             unsigned long long
#define INF             9223372036854775807
#define mnh             priority_queue<ll, vector<ll>, greater<ll>>
#define endl            "\n"
#define w(t)            ll tests;    cin>>tests;        while(tests--)
#define pb(x)           push_back(x)
#define ppb()           pop_back()
#define all(x)          x.begin(), x.end()
#define mp(a, b)        make_pair(a, b)
#define setp(x, y)      fixed << setprecision(x) << y
#define f(i, a, b)      for(ll i = a ; i < b ; i++)
#define fo(j, a, b)     for(ll j = a ; j >= b ; j--)
#define fill(a, n, x)   f(i, 0, n)     a[i]=x;
using namespace std;

void init() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int main() {

    init();
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    w(t)
    {
        ll p;
        cin >> p;

        cout << (p - 1) / 2 << " " << (p - 1) << endl;
    }

    return 0;
}