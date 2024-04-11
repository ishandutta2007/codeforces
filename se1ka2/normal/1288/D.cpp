#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll a[300005][10];

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> a[i][j];
    ll now = 0;
    ll mid = 1048576 * 1024 / 2;
    while(mid){
        bool f[300]{0};
        for(int i = 0; i < n; i++){
            int b = 0;
            for(int j = 0; j < m; j++) if(a[i][j] >= now) b += (1 << j);
            if(f[b]) continue;
            for(int t = 0; t < (1 << m); t++){
                if((b & t) == t) f[t] = true;
            }
        }
        bool g = false;
        for(int t = 0; t < (1 << m); t++){
            if(f[t] && f[(1 << m) - 1 - t]) g = true;
        }
        if(g) now += mid;
        else now -= mid;
        mid /= 2;
    }
    bool f[300]{0};
    for(int i = 0; i < n; i++){
        int b = 0;
        for(int j = 0; j < m; j++) if(a[i][j] >= now) b += (1 << j);
        if(f[b]) continue;
        for(int t = 0; t < (1 << m); t++){
            if((b & t) == t) f[t] = true;
        }
    }
    bool g = false;
    for(int t = 0; t < (1 << m); t++){
        if(f[t] && f[(1 << m) - 1 - t]) g = true;
    }
    if(!g) now--;
    bool f_[300]{0};
    int p[300005];
    for(int i = 0; i < n; i++){
        int b = 0;
        for(int j = 0; j < m; j++) if(a[i][j] >= now) b += (1 << j);
        p[i] = b;
        if(f_[b]) continue;
        for(int t = 0; t < (1 << m); t++){
            if((b & t) == t) f_[t] = true;
        }
    }
    bool g1 = false, g2 = false;
    for(int t = 0; t < (1 << m); t++){
        if(f_[t] && f_[(1 << m) - 1 - t]){
            for(int i = 0; i < n; i++){
                if((p[i] & t) == t && !g1){
                    cout << i + 1 << " ";
                    g1 = true;
                }
                if((p[i] & ((1 << m) - 1 - t)) == (1 << m) - 1 - t && !g2){
                    cout << i + 1 << " ";
                    g2 = true;
                }
            }
        }
    }
}