#include <iostream>
using namespace std;
typedef long long ll;

ll dist(ll x0, ll y0, ll x1, ll y1){
    return (x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1);
}

int main()
{
    int n;
    cin >> n;
    ll x[5005], y[5005];
    for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
    int b[5005]{0};
    int u = 0;
    for(int i = 0; i < n; i++){
        cout << u + 1 << " ";
        b[u] = true;
        int v = -1;
        for(int j = 0; j < n; j++){
            if(!b[j] && (v == -1 || dist(x[u], y[u], x[j], y[j]) > dist(x[u], y[u], x[v], y[v]))) v = j;
        }
        u = v;
    }
    cout << endl;
}