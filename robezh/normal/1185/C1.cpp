#include <bits/stdc++.h>
using namespace std;

const int N = (int)2e5 + 50;

int n, M;
int t[N];
int cnt[N];

int main() {
    cin >> n >> M;
    for(int i = 0; i < n; i++) {
        cin >> t[i];
        int mx_bef = 0;
        int rem = M - t[i];
        for(int j = 1; j <= 100; j++) {
            if(cnt[j] * j <= rem) {
                mx_bef += cnt[j];
                rem -= cnt[j] * j;
            }
            else {
                int take = rem / j;
                mx_bef += take;
                break;
            }
        }
        cnt[t[i]]++;
        cout << i - mx_bef << " ";
    }
}