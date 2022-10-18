#include<bits/stdc++.h>
#define y1 kdfjdfldsfbjd
using namespace std;
const int N = 4e5 + 5;
int a[N], b[N], c[N], k1, k2, k3, n, d[N], k4;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >>n;
    long long ans = 0, k = 0;
    for (int i = 1; i <= n; ++i){
        string s;
        cin >>s;
        int x;
        cin >>x;
        if (s == "00")a[++k1] = x;
        if (s == "01")b[++k2] = x;
        if (s == "10")c[++k3] = x;
        if (s == "11"){
            ans += x;
            k++;
        }
    }
    sort(a + 1, a + k1 + 1);
    reverse(a + 1, a + k1 + 1);
    sort(b + 1, b + k2 + 1);
    reverse(b + 1, b + k2 + 1);
    sort(c + 1, c + k3 + 1);
    reverse(c + 1, c + k3 + 1);
    int tt = k;
    for (int i = 1; i <= min(k2, k3); ++i){
        k++;
        ans += b[i] + c[i];
    }
    if (k2 < k3){
        for (int i = k2 + 1; i <= k3; ++i){
            d[++k4] = c[i];
        }
    }else {
        for (int i = k3 + 1; i <= k2; ++i){
            d[++k4] = b[i];
        }
    }
    int p1 = 1, p4 = 1;
    while (tt-- && (p1 <= k1 || p4 <= k4)){
        if (p1 > k1 || (p4 <= k4 && d[p4] > a[p1])){
            ans += d[p4++];
        }else ans += a[p1++];
    }
    cout <<ans;
}