#include <bits/stdc++.h>
using namespace std;

int n,d,a;
int cnt[105];

int get(int t){
    int sum = 0;
    for(int i = t; i <= t+d; i++){
        sum += cnt[i];
    }
    return sum;
}

int main() {
    fill(cnt, cnt+105, 0);
    cin >> n >> d;
    for(int i = 0; i < n; i++){
        cin >> a;
        cnt[a] ++;
    }
    int res = n - get(1);
    for(int i = 1; i <= 100-d; i++){
        res = min(res, n-get(i));
    }
    cout << res;
}