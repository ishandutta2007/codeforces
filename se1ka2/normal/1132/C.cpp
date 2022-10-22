#include <algorithm>
#include <iostream>
using namespace std;
typedef pair<int, int> P;

int dp[5003][5003];

int main()
{
    int n, q;
    cin >> n >> q;
    int l[5003], r[5003];
    int d[5003] {0};
    for(int i = 0; i < q; i++){
        cin >> l[i] >> r[i];
        l[i]--;
        r[i]--;
        for(int j = l[i]; j <= r[i]; j++) d[j]++;
    }
    int ans = 0;
    for(int i = 0; i < q; i++){
        for(int j = l[i]; j <= r[i]; j++) d[j]--;
        int e[5003] {0};
        int s = 0;
        for(int j = 0; j < n; j++){
            if(j) e[j] = e[j - 1];
            if(d[j]){
                if(d[j] == 1) e[j]++;
                s++;
            }
        }
        for(int j = 0; j < q; j++){
            if(j == i) continue;
            if(l[j] == 0) ans = max(ans, s - e[r[j]]);
            else ans = max(ans, s - e[r[j]] + e[l[j] - 1]);
        }
        for(int j = l[i]; j <= r[i]; j++) d[j]++;
    }
    cout << ans << endl;
}