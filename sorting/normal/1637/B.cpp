#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

int mex(const set<int> &s){
    int ans = 0;
    while(s.count(ans))
        ++ans;
    return ans;
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

        int ans = 0;
        for(int i = 1; i <= n; ++i)
            ans += (n - i + 1) * i;

        for(int i = 0; i < n; ++i)
            if(!a[i])
                ans += (i + 1) * (n - i);

        cout << ans << "\n";
    }
}