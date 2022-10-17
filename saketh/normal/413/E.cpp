#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 2e5 + 200;

int N, Q;
int grid[MAXN];

int conn[MAXN];
int lft[MAXN], rgt[MAXN];

int pref[MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N >> Q;
    string a, b;
    cin >> a >> b;

    for (int i = 0; i < N; i++) {
        bool top = a[i] == '.';
        bool bot = b[i] == '.';
        grid[i] = 2 * top + bot;

        if(i) {
            bool diff = false;
            if(grid[i-1] == 0 || grid[i] == 0) diff = true;
            if(grid[i-1] == 1 && grid[i] == 2) diff = true;
            if(grid[i-1] == 2 && grid[i] == 1) diff = true;
            conn[i] = conn[i-1] + diff;
        }
    }
    
    for (int i = 0; i < N; i++) {
        if(grid[i] != 3) lft[i] = i;
        else lft[i] = i ? lft[i-1] : -1;
    }

    for (int i = N - 1; i >= 0; i--) {
        if(grid[i] != 3) rgt[i] = i;
        else rgt[i] = (i+1 < N) ? rgt[i+1] : N;
    }

    int prev = 0;
    for (int i = 0; i < N; i++) {
        // first let's compute pref
        if(i) pref[i] = pref[i-1];
        if(grid[i] == 2 && prev == 1) pref[i]++;
        if(grid[i] == 1 && prev == 2) pref[i]++;

        // now update prev
        if(grid[i] == 3) continue;
        prev = grid[i];
    }

    for (int i = 0; i < Q; i++) {
        int A, B;
        cin >> A >> B;
        A--, B--;

        int ac = A % N, ar = A / N;
        int bc = B % N, br = B / N;
    
        if(ac > bc) { swap(ac, bc); swap(ar, br); }

        if(conn[ac] != conn[bc]) { cout << -1 << "\n"; continue; }

        int dist = bc - ac;
        ac = rgt[ac];
        bc = lft[bc];

        if(ac <= bc) {
            if(ar && grid[ac] == 2) dist++;
            if(!ar && grid[ac] == 1) dist++;
            if(br && grid[bc] == 2) dist++;
            if(!br && grid[bc] == 1) dist++;
            dist += pref[bc] - pref[ac];
        }
        else dist += (ar != br);
        cout << dist << endl;
    }
}