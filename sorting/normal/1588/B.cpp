#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

ll query(int l, int r){
    cout << "? " << l << " " << r << "\n";
    cout.flush();
    ll inv;
    cin >> inv;
    return inv; 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        int l = 1, r = n;
        ll total = query(1, n);
        while(l != r){
            int mid = (l + r) >> 1;
            if(query(1, mid) == total) r = mid;
            else l = mid + 1;
        }

        int k = l;
        ll x = query(1, k) - query(1, k - 1);
        int j = k - x, i;
        if(j == 2) i = 1;
        else{
            ll x2 = query(1, j - 1) - query(1, j - 2);
            i = j - 1 - x2;
        }

        cout << "! " << i << " " << j << " " << k << "\n";
        cout.flush();
    }
}