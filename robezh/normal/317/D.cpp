#include <bits/stdc++.h>
using namespace std;

int sg[31] = {0, 1, 1, 2, 1, 4, 3, 2, 1, 5, 6, 2, 1, 8, 7, 5, 9, 8, 7, 3, 4, 7, 4, 2, 1, 10, 9, 3, 6, 11, 12};

typedef long long ll;
int n;
map<int, int> mp;
int f_res = 0;

int main() {
    cin >> n;
    for(int i = 2; i * i <= n; i++) {
        if(mp.count(i)) continue;
        ll cur = i;
        int cnt = 1;
        while(cur <= n) {
            mp[cur] = 1;
            cnt++;
            cur *= i;
        }
        f_res ^= sg[cnt];
    }
    int tot_1 = n - 1 - mp.size();
    if(tot_1 % 2 == 1) f_res ^= 1;
    f_res ^= 1;
    cout << (f_res ? "Vasya" : "Petya") << endl;

}