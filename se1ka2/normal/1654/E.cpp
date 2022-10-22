#include <iostream>
using namespace std;

int d_[100000000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int a[100005];
    for(int i = 0; i < n; i++) cin >> a[i];
    int ans = 0;
    int *d = d_ + 50000000;
    for(int r = -400; r <= 400; r++){
        for(int i = 0; i < n; i++) d[a[i] + r * i]++;
        for(int i = 0; i < n; i++){
            ans = max(ans, d[a[i] + r * i]);
            d[a[i] + r * i]--;
        }
    }
    for(int i = 0; i < n; i++){
        int v[505];
        int k = 0;
        for(int j = i + 1; j < min(n, i + 250); j++){
            int x = (a[j] - a[i]) / (j - i);
            if((j - i) * x != (a[j] - a[i])) continue;
            d[x]++;
            v[k++] = x;
        }
        for(int i = 0; i < k; i++){
            ans = max(ans, d[v[i]] + 1);
            d[v[i]]--;
        }
    }
    cout << n - ans << "\n";
}