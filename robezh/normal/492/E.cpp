#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e6 + 500;

int n,m,dx,dy,x,y;
int cnt[N];
int step[N];

int main(){
    scanf("%d%d%d%d", &n, &m, &dx, &dy);

    int cx = 0, cy = 0;
    for(int i = 0; i < n; i++){
        step[cx] = cy;
        cx = (cx + dx) % n;
        cy = (cy + dy) % n;
    }

    for(int i = 0; i < m; i++){
        scanf("%d%d", &x, &y);
        int ny = (step[n - x] + y) % n;
        cnt[ny]++;
    }
    int mxi = 0;
    for(int i = 0; i < n; i++){
        if(cnt[i] > cnt[mxi]) mxi = i;
    }
    //cout << cnt[mxi] << endl;
    cout << 0 << " " << mxi << endl;
}