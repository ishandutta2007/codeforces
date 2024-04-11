#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define int long long
#define p pair<int, int>
#define endl '\n'
const int INF = 1000000001;

using namespace std;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    int C = 1000179;
    vector<int> d(C);
    vector<bool> prime(C, true);
    prime[0] = prime[1] = false, d[0] = 0;
    for (int q = 2; q < C; q++){
        if (prime[q]){
            for (int q1 = q*q; q1 < C; q1 += q){
                prime[q1] = false;
            }
        }
    }
    for (int q = 1; q < C; q++){
        d[q] = d[q-1]+prime[q];
        if ((int)sqrt(q)*(int)sqrt(q) == q){
            d[q] -= prime[(int)sqrt(q)];
        }
    }
    for (int q = 0; q < n; q++){
        int k;
        cin >> k;
        cout << d[k]+1 << endl;
    }
    return 0;
}