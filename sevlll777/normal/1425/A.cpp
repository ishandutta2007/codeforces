#include<bits/stdc++.h>
#define int long long
#define p pair<int, int>
#define endl '\n'
const int INF = 1000000001;
const long double E = 0.00000001;

using namespace std;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t1;
    cin >> t1;
    for (int q11 = 0; q11 < t1; q11++){
        int n;
        cin >> n;
        int ans = 0, q1 = 0;
        while (n > 0){
            if (n % 2 == 0 && (n % 4 != 0 || n == 4)){
                ans += n/2*(1-q1);
                n /= 2;
            }else{
                ans += (1-q1);
                n--;
            }
            q1 = 1-q1;
        }
        cout << ans << endl;
    }
    return 0;
}