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
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    int n, k, q;
    cin >> n >> k >> q;

    vector <int> a(n);
    for (int i = 0; i < n; ++i) 
        cin >> a[i];

    set <int> ms;

    vector <bool> used(n);

    for (int t = 0; t < q; ++t) {
        int tp, i;
        cin >> tp >> i;
        --i;

        if (tp == 1) {
            ms.insert(a[i]);                    
            used[i] = 1;
        }   
        else {

            auto it = ms.end();
            for (int j = 0; j < k && it != ms.begin(); ++j) {
                --it;
            }   

            if (*it <= a[i] && used[i])
                cout << "YES" << endl;
            else
                cout << "NO" << endl;

        }   

    }   


}