#include <algorithm>
#include <iostream>
using namespace std;
typedef pair<int, int> P;

bool cross(int i, int j, int *x, int *y){
    P d[4] = {P(x[i], i), P(y[i], i), P(x[j], j), P(y[j], j)};
    sort(d, d + 4);
    if(d[0].second == d[2].second) return true;
    return false;
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int x[102], y[102];
        bool b[202]{0};
        for(int i = 0; i < k; i++){
            cin >> x[i] >> y[i];
            x[i]--; y[i]--;
            b[x[i]] = b[y[i]] = true;
        }
        int c = 0;
        int j;
        for(j = 0; j < n * 2; j++){
            if(c == n - k) break;
            if(!b[j]) c++;
        }
        int i = 0;
        for(; k < n; k++){
            while(b[i]) i++;
            b[i] = true;
            while(b[j]) j++;
            b[j] = true;
            x[k] = i, y[k] = j;
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(cross(i, j, x, y)) ans++;
            }
        }
        cout << ans << endl;
    }
}