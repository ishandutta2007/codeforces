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
        int n, d;
        cin >> n >> d;

        vector<int> a(n);
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        sort(all(a));

        if(a.back() <= d || a[0] + a[1] <= d)
            cout << "yes\n";
        else
            cout << "no\n";
    }
}