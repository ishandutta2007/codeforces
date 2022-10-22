#include <algorithm>
#include <iostream>
using namespace std;
typedef pair<int, int> P;

int main()
{
    int n;
    cin >> n;
    int a[1002];
    P p[1002][1002];
    int c[1002]{0};
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int u = 0; u < n; u++){
        for(int v = u + 1; v < n; v++){
            if(a[v] < a[u]){
                p[v][c[v]] = P(a[u], u);
                c[v]++;
            }
        }
    }
    for(int v = 0; v < n; v++) sort(p[v], p[v] + c[v]);
    int ans = 0;
    for(int v = 0; v < n; v++) ans += c[v];
    cout << ans << endl;
    for(int v = n - 1; v >= 0; v--){
        for(int i = 0; i < c[v]; i++){
            int u = p[v][i].second;
            cout << u + 1 << " " << v + 1 << endl;
        }
    }
}