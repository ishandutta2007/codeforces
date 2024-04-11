#include <bits/stdc++.h>
using namespace std;

int n,k;
int tap[205];

int main() {
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 0; i < k; i++){cin >> tap[i]; tap[i] --;}
        sort(tap, tap+k);
        int res = max(tap[0]+1, n - tap[k-1]);
        for(int i = 0; i < k-1; i++){
            res = max(res, (tap[i+1]-tap[i])/2 + 1);
        }
        cout << res << endl;
    }
}