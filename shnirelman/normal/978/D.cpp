#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    if(n <= 2){
        cout << 0;
        return 0;
    }

    int ans = n + 1;
    for(int d0 = -1; d0 <= 1; d0++)
        for(int d1 = -1; d1 <= 1; d1++){

            vector<int> b = a;
            b[0] += d0;
            b[1] += d1;
            int k = b[1] - b[0];

            int cnt = abs(d0) + abs(d1);
            for(int i = 2; i < n; i++)
                if(b[i] - b[i-1] == k + 1){
                    b[i]--;
                    cnt++;
                }
                else if(b[i] - b[i-1] == k - 1){
                    b[i]++;
                    cnt++;
                }
                else if(b[i] - b[i-1] != k){
                    cnt = n + 1;
                    break;
                }

            //cout << d0 << ' ' << d1 << ' ' << k << ' ' << cnt << endl;
            ans = min(cnt, ans);

        }

    if(ans == n+1)cout << -1;
    else cout << ans;
}