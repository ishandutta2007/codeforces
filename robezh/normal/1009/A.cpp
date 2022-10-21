#include <bits/stdc++.h>
using namespace std;

#define N 1005

int n,m;
int cost[N], bill[N];

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> cost[i];
    for(int i = 0; i < m; i++) cin >> bill[i];
    int j = 0, ans = 0;
    for(int i = 0; i < n; i++){
        if(j < m && bill[j] >= cost[i]){
            j++, ans++;
        }
    }
    cout << ans;
}