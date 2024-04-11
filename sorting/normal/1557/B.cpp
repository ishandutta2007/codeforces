#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for(int i = 0; i < n; ++i)
            cin >> a[i];

        vector<int> a2 = a;
        sort(all(a2));

        int cnt = 1;
        for(int i = 0; i < n - 1; ++i){
            if(lower_bound(all(a2), a[i]) == a2.end() - 1)
                ++cnt;
            else{
                if(*(lower_bound(all(a2), a[i]) + 1) != a[i + 1])
                    ++cnt;
            }
        }

        cout << ((cnt <= k) ? "Yes" : "No") << "\n";
    }
}