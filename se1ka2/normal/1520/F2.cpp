#include <iostream>
using namespace std;

int d[1000005];

void query(int k, int n){
    int nn = 1;
    while(nn < n) nn <<= 1;
    if(d[1] == -1){
        cout << "? 1 " << n << endl;
        cin >> d[1];
        d[1] = n - d[1];
    }
    int u = 1;
    int l = 0, r = nn;
    while(u < nn){
        int m = (l + r) / 2;
        if(d[u * 2] == -1){
            cout << "? " << l + 1 << " " << min(m, n) << endl;
            cin >> d[u * 2];
            d[u * 2] = (min(m, n) - l) - d[u * 2];
            d[u * 2 + 1] = d[u] - d[u * 2];
        }
        if(k <= d[u * 2]){
            u = u * 2;
            r = m;
        }
        else{
            k -= d[u * 2];
            u = u * 2 + 1;
            l = m;
        }
    }
    cout << "! " << u - nn + 1 << endl;
    while(u){
        d[u]--;
        u /= 2;
    }
}

int main()
{
    int n, t;
    cin >> n >> t;
    for(int i = 0; i < n * 4; i++) d[i] = -1;
    while(t--){
        int k;
        cin >> k;
        query(k, n);
    }
}