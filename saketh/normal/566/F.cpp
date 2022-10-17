#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1000100;

int N;
int val[MAXN];
int idx[MAXN];
int len[MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N;
    
    for (int i = 1; i <= N; i++) {
        cin >> val[i];
    }

    for (int i = 1; i <= N; i++) {
        idx[val[i]] = i;
    }

    int ans = 1;

    for (int i = 1; i <= N; i++) {
        len[i] = max(len[i], 1);
        for (int j = 2*val[i]; j < MAXN; j += val[i]) {
            if(idx[j] == 0) continue;
            len[idx[j]] = max(len[idx[j]], len[i] + 1);
            ans = max(ans, len[idx[j]]);
        } 
    }

    cout << ans << endl;
}