#include <iostream>

using namespace std;

    int sums[11][101][101];
int main() {
    int n,q,c;
    cin >> n >> q >> c;
    int y, x, in;
    int mom, minx, miny, maxx, maxy;
    for(int i = 0; i < n; i++){
        cin >> x >> y >> in;
        for(int j = 0; j < 11; j++){
            sums[j][y][x] += (in + j) % (c+1);
        }
    }
    for(int e = 0; e < 11; e++){
        for(int i = 1; i < 101; i++){
            for(int j = 1; j < 101; j++){
                sums[e][i][j] = (sums[e][i][j-1]+ sums[e][i-1][j] - sums[e][i-1][j-1] + sums[e][i][j]);
            }
        }
    }
    for(int i = 0; i < q; i++){
        cin >> mom >> minx >> miny >> maxx >> maxy;
        mom = mom % (c+1);
        cout << (sums[mom][maxy][maxx] - sums[mom][miny-1][maxx] - sums[mom][maxy][minx-1] + sums[mom][miny-1][minx-1]) << '\n';
    }
    
}