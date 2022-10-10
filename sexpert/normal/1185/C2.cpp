#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int ct[105];
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int n, M, sum = 0;
    cin >> n >> M;
    vector<int> v(n);
    for(auto &x : v)
        cin >> x;
    for(int i = 0; i < n; i++) {
        int tmp = sum, rejects = 0;
        for(int c = 100; c >= 1; c--) {
            if(tmp + v[i] <= M) break;
            if(tmp - c*ct[c] + v[i] > M) {
                tmp -= c*ct[c];
                rejects += ct[c];
                continue;
            }
            //t - c*k + v[i] <= M
            //ck >= t + v[i] - M
            int k = (tmp + v[i] - M)/c;
            while(tmp - c*k + v[i] > M)
                k++;
            rejects += k;
            break;
        }
        cout << rejects << " ";
        sum += v[i];
        ct[v[i]]++;
    }
    cout << '\n';
}