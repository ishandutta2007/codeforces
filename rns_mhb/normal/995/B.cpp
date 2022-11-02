#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector <int> a(2*n+1);
    for(int i = 1; i <= 2*n; i ++) cin >> a[i];
    int ans = 0;
    for(int i = 1; i <= 2*n; i += 2) {
        int j;
        for(j = i+1; j <= 2*n; j ++) if(a[i] == a[j]) break;
        while(j > i+1) swap(a[j-1], a[j]), j --, ans ++;
    }
    cout << ans << endl;
}