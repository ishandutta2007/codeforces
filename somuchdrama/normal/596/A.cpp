#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define sqr(x) ((x) * (x))
#define rep(a,b,c) for(int a=b;a<c;++a)
#define per(a,b,c) for(int a=b;a>c;--a)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;




int main() {
    ios_base::sync_with_stdio(0);
    srand(time(NULL));
    cout << fixed;
    cout.precision(10);
    cerr << fixed;
    cerr.precision(10);
    
    int n;
    cin >> n;
    pii arr[4];
    for (int i = 0; i < n; ++i) 
        cin >> arr[i].ff >> arr[i].ss;


    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[i].ff == arr[j].ff)
                continue;
            if (arr[i].ss == arr[j].ss)
                continue;
            cout << abs(arr[j].ff - arr[i].ff) * abs(arr[j].ss - arr[i].ss) << '\n';
            return 0;
        }
    }


        cout << "-1\n";

    return 0;
}