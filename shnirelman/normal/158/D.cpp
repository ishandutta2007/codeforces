#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int INF = 1000 * 20000 + 12;

int main(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++)cin >> a[i];

    vector<int> d;
    for(int i = 1; i < min(n / 2 + 3, n); i++)
        if(n % i == 0 && n / i >= 3)d.push_back(i);

    int ans = -INF;

    for(int i = 0; i < d.size(); i++){
        for(int j = 0; j < d[i]; j++){
            int sum = 0;
            for(int l = j; l < n; l += d[i])sum += a[l];
            ans = max(sum, ans);
        }
    }

    cout << ans;
}