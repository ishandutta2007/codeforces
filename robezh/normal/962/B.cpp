#include <bits/stdc++.h>
using namespace std;

int n,a,b;
char c[200050];

int main() {
    cin >> n >> a >> b;
    int free = 0, base = 0;
    int now = 0;
    for(int i = 0; i < n; i++){
        cin >> c[i];
        if(c[i] == '*') free += now%2, base += now/2, now = 0;
        else now++;
    }
    free += now%2, base += now/2, now = 0;
    int res = 0;
    for(int i = 0; i <= free; i++){
        int cool = min(a, i+base) + min(b, (free-i) + base);
        res = max(res, cool);
    }

    cout << res;

}