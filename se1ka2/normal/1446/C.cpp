#include <algorithm>
#include <iostream>
using namespace std;

int dfs(int l, int r, int k, int *b){
    if(l == r) return 0;
    int res = 0;
    int c = 0;
    int ll = l;
    for(int j = k - 1; j >= -1; j--){
        if(j == -1){
            res = max(res, c + 1);
            break;
        }
        if(!((b[ll] >> j) & 1)) continue;
        int i;
        for(i = ll; i < r; i++){
            if(!((b[i] >> j) & 1)) break;
        }
        int d = dfs(ll, i, j, b);
        if(i == r){
            res = max(res, c + d);
            break;
        }
        ll = i;
        c++;
        res = max(res, c + d);
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    int b[200005];
    for(int i = 0; i < n; i++) cin >> b[i];
    sort(b, b + n, greater<int>());
    cout << n - dfs(0, n, 30, b) << endl;
}