#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> h(n);
    for(int i = 0; i < n; ++i)
        cin >> h[i];

    int mx = 0;
    vector<int> ans(n);
    for(int i = n - 1; i >= 0; --i){
        if(mx < h[i])
            ans[i] = 0;
        else
            ans[i] = mx - h[i] + 1;
        check_max(mx, h[i]);
    }

    for(int x: ans)
        cout << x << " ";
    cout << "\n";
}