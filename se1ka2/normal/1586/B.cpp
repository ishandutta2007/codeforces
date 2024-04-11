#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int d[100005];
        for(int i = 0; i < n; i++) d[i] = 0;
        for(int i = 0; i < m; i++){
            int a, b, c;
            cin >> a >> b >> c;
            a--; b--; c--;
            d[b]++;
        }
        int u;
        for(u = 0; u < n; u++){
            if(d[u] == 0) break;
        }
        for(int v = 0; v < n; v++){
            if(u != v) cout << u + 1 << " " << v + 1 << endl;
        }
    }
}