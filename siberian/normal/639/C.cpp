#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
#define debug(x) std::cout << #x << ": " << x << '\n';

const int N = 3e5+7, INF = 1e18+7;

vector <int> inv(vector <int> a) {
    for (int &e : a)
        e = -e;
    return a;
}

bool check(vector <int> a) {
    while (a.size() < N) 
        a.app(0);

    int add = 0;
    for (int i = 0; i < N; ++i) {

        a[i] += add;
        add = 0;
        if (a[i] > 0) {
            int k = a[i]/2;
            add = k;
            a[i] %= 2;
        }   
        else if (a[i] < 0) {
            int k = (-a[i] + 1) / 2;
            add = -k;
            a[i] += 2 * k;
        }   

    }   
    
    return add == 0;
}   

ii get(vector <int> a) {
    while (a.size() < N) 
        a.app(0);

    int add = 0;
    for (int i = 0; i < N; ++i) {

        a[i] += add;
        add = 0;
        if (a[i] > 0) {
            int k = a[i]/2;
            add = k;
            a[i] %= 2;
        }   
        else if (a[i] < 0) {
            int k = (-a[i] + 1) / 2;
            add = -k;
            a[i] += 2 * k;
        }   

    }   

    assert(add == 0);

    int l = -1;
    for (int i = 0; i < N; ++i)
        if (a[i]) {
            l = i;
            break;
        }   

    assert(l != -1);

    int ans = 0;
    for (int i = l; i < N; ++i) {
        if (a[i]) {

            assert(a[i] == 1);
            
            if (i - l > 60) {
                cout << 0 << endl;
                exit(0);
            }   

            ans += 1ll << (i - l);
        }   
    }   
    return mp(ans, l);
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    int n, k;
    cin >> n >> k;
    vector <int> a(n + 1);
    for (int i = 0; i <= n; ++i)
        cin >> a[i];

    if (!check(a) && !check(inv(a))) {
        cout << 0 << endl;
        exit(0);        
    }   

    ii x = {-1, -1};

    int sign;

    // f, 2^s
    
    if (check(a)) {
        x = get(a);
        sign = -1;
    }   
    else {
        x = get(inv(a));
        sign = 1;
    }   

    int cur = x.f;
    int ans = 0;
        
    #ifdef HOME
    cout << x.f << ' ' << x.s << ' ' << sign << endl;
    #endif

    for (int i = x.s; i >= 0; --i) {

        if (abs(a[i] + cur * sign) <= k) {
            if (!(i == n && a[i] + cur * sign == 0)) {
                ++ans;
            }
        }

        cur <<= 1;
        if (abs(cur) > INF) {
            cout << ans << endl;
            exit(0);
        }   
    }   
    cout << ans << endl;
}