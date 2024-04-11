#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll gcd(ll n, ll m){
    if(n % m == 0) return m;
    return gcd(m, n % m);
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll a[100005];
        for(int i = 0; i < n; i++) cin >> a[i];
        int l = 0;
        for(int i = 0; i < n; i++){
            if(a[i] < a[l]) l = i;
        }
        vector<int> ans[4];
        if(l != n - 1){
            swap(a[l], a[n - 1]);
            ans[0].push_back(l);
            ans[1].push_back(n - 1);
            ans[2].push_back(a[l]);
            ans[3].push_back(a[n - 1]);
        }
        int s = a[n - 1] + n - 1;
        for(int i = 0; i < n - 1; i++){
            a[i] = s - i;
            ans[0].push_back(i);
            ans[1].push_back(n - 1);
            ans[2].push_back(a[i]);
            ans[3].push_back(a[n - 1]);
        }
        int k = ans[0].size();
        cout << k << endl;
        for(int i = 0; i < k; i++){
            cout << ans[0][i] + 1 << " " << ans[1][i] + 1 << " " << ans[2][i] << " " << ans[3][i] << endl;
        }
    }
}