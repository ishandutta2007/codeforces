#include <bits/stdc++.h>
using namespace std;

int cnt[605];

int main() {
    fill(cnt,cnt+605,0);
    int n,a;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        cnt[a] ++;
    }
    int res = 0;
    for(int i = 1; i <= 600; i++){
        if(cnt[i] > 0) res ++;
    }
    cout << res;
    return 0;
}