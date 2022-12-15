#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

bool is_composite(int x){
    for(int i = 2; i * i <= x; ++i)
        if(x % i == 0)
            return true;
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> a(n);
        for(int &x: a)
            cin >> x;

        int sum = accumulate(all(a), 0);
        if(is_composite(sum)){
            cout << n << "\n";
            for(int i = 0; i < n; ++i)
                cout << i + 1 << " ";
            cout << "\n";
            continue;
        }
        bool ok = false;
        for(int i = 0; i < n; ++i){
            if(is_composite(sum - a[i])){
                cout << n - 1 << "\n";
                for(int j = 0; j < i; ++j)
                    cout << j + 1 << " ";
                for(int j = i + 1; j < n; ++j)
                    cout << j + 1 << " ";
                cout << "\n";
                ok = true;
                break;
            }
        }
        if(ok) continue;
    }
}