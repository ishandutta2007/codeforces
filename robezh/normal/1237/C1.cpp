#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;


const int N = (int)1e5 + 50;

struct node {
    int x, y, z, i;
} nds[N];

int rm[N];

int n;

bool better(node &c, node &o, node &n) {
    if(abs(c.x - o.x) != abs(c.x - n.x)) return abs(c.x - o.x) > abs(c.x - n.x);
    if(abs(c.y - o.y) != abs(c.y - n.y)) return abs(c.y - o.y) > abs(c.y - n.y);
    return abs(c.z - o.z) > abs(c.z - n.z);
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> nds[i].x >> nds[i].y >> nds[i].z;
        nds[i].i = i + 1;
    }
    for(int it = 0; it < n / 2; it++) {
        int fir = -1;
        for(int i = 0; i < n; i++) {
            if(!rm[i]) {
                fir = i;
                break;
            }
        }
        int best = -1;
        for(int j = fir + 1; j < n; j++) {
            if(rm[j]) continue;
            if(best == -1 || better(nds[fir], nds[best], nds[j])) best = j;
        }
        rm[fir] = rm[best] = 1;
        cout << fir + 1 << ' ' << best + 1 << '\n';
    }

}