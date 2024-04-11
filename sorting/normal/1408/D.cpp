#include <bits/stdc++.h>

using namespace std;

const int k_N = 2000 + 3;
const int k_Inf = 1e9 + 3;

int a[k_N], b[k_N], c[k_N], d[k_N];
array<int, 2> arr[k_N * k_N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; ++i)
        cin >> a[i] >> b[i];
    for(int i = 0; i < m; ++i)
        cin >> c[i] >> d[i];

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            arr[i * m + j] = {max(c[j] - a[i], -1), max(d[j] - b[i], -1)};

    sort(arr, arr + n * m);

    //for(int i = n * m - 1; i >= 0; --i)
    //    cout << arr[i][0] << "," << arr[i][1] << " ";
    //cout << "\n";

    int curr_max = -k_Inf, ans = k_Inf;
    for(int i = n * m - 1; i >= 0; --i){
        if(arr[i][1] <= curr_max) continue;

        if(curr_max != -k_Inf)
            ans = min(ans, 2 + curr_max + arr[i][0]);
        else
            ans = min(ans, 1 + arr[i][0]);

        curr_max = arr[i][1];
        //cout << ans <<  " " << i << " ans\n";
    }
    ans = min(ans, 1 + curr_max);

    cout << ans << "\n";
}