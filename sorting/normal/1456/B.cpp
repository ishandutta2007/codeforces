#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 3;

int n, a[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i];

    for(int i = 0; i < n - 2; ++i){
        if((a[i + 2] ^ a[i + 1]) < a[i]){
            cout << "1\n";
            return 0;
        }
    }

    int ans = N;
    for(int i = 0; i < n - 1; ++i){
        int left = 0;
        for(int j = i; j >= 0; --j){
            left ^= a[j];
            int right = 0;
            for(int k = i + 1; k < n; ++k){
                right ^= a[k];
                if(left > right)
                    ans = min(ans, i - j + k - (i + 1));
            }
        }
    }

    if(ans == N) cout << "-1\n";
    else cout << ans << '\n';
}