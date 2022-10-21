#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 50;

int num[N];
int ser[N], dis[N];
int las[N];
int res[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        int n, m;
        cin >> m >> n;
        m--;
        for(int i = 0; i < n; i++) cin >> num[i];
        fill(las, las + n, -1);
        fill(res, res + n, 0);
        int fir = -1;
        for(int i = 0; i < m; i++) {
            cin >> ser[i] >> dis[i];
            ser[i]--;
            if(ser[i] != -1) las[ser[i]] = i;
            if(dis[i] && fir == -1) fir = i;
        }
        int free = 0;
        for(int i = 0; i < fir; i++) {
            if(ser[i] == -1) free++;
            else num[ser[i]]--;
        }
        int mx = -1;
        if(fir != -1) {
            for(int i = 0; i < n; i++) {
                if(las[i] < fir) {
                    if(free >= num[i]) {
                        res[i] = 1;
                        if(mx == -1 || num[mx] > num[i]) mx = i;
                    }
                }
            }
        }
        if(mx != -1) free -= num[mx];
        for(int i = max(0, fir); i < m; i++) {
            if(ser[i] == -1) free++;
            else num[ser[i]]--;
        }
        for(int i = 0; i < n; i++) if(!res[i]) res[i] = (free >= num[i]);
        for(int i = 0; i < n; i++) cout << (res[i] ? "Y" : "N");
        cout << endl;




    }
}