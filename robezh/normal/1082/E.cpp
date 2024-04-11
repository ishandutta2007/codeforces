#include <bits/stdc++.h>
using namespace std;

const int N = (int)5e5 + 500;

int n,c;
int a[N];
int cnt[2][N];
int mx[2][N];

int solve(int L, int R){
    if(L == R) return a[L] != c;

    int mid = (L + R) / 2;
    int res = 0;
//    int cnt_c;
    for(int i = mid; i >= L; i--){
        cnt[0][a[i]] ++;
        mx[0][a[i]] = max(mx[0][a[i]], cnt[0][a[i]] - cnt[0][c]);
    }
    for(int i = mid + 1; i <= R; i++){
        cnt[1][a[i]] ++;
        mx[1][a[i]] = max(mx[1][a[i]], cnt[1][a[i]] - cnt[1][c]);
    }
    for(int i = L; i <= R; i++){
        res = max(res, mx[0][a[i]] + mx[1][a[i]]);
    }
    for(int i = L; i <= R; i++){
        mx[0][a[i]] = mx[1][a[i]] = 0;
        cnt[0][a[i]] = cnt[1][a[i]] = 0;
    }
    res = max(res, max(solve(L, mid), solve(mid+1, R)));
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int base = 0;
    cin >> n >> c;
    for(int i = 0; i < n; i++) cin >> a[i], base += (a[i] == c);

//    cout << base << endl;
//    cout << solve(0, n-1) << endl;
    cout << base + solve(0, n-1) << endl;

}