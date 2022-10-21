#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)2e5 + 500;

int n,k;
int sz[N];


int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> sz[i];
    sort(sz, sz+n);
    int res = 0;
    int las = 0;
    for(int i = 1; i < n; i++){
        if(sz[i] == sz[las]) continue;
        if(sz[i] - sz[las] <= k)
            res += i - las;
        las = i;
    }
    cout << n - res;
}