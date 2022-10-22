#include <algorithm>
#include <iostream>
using namespace std;
typedef pair<int, int> P;

int x[100002], y[100002];
P px[100002], py[100002];
int d[100002][4];

int main()
{
    int q;
    cin >> q;
    for(int c = 0; c < q; c++){
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
            scanf("%d %d", &x[i], &y[i]);
            scanf("%d %d %d %d", &d[i][0], &d[i][1], &d[i][2], &d[i][3]);
            px[i] = P(x[i], i);
            py[i] = P(y[i], i);
        }
        sort(px, px + n);
        sort(py, py + n);
        bool f = true;
        int i = 0;
        int ax = 100000;
        for(; i < n; i++){
            if(d[px[i].second][2] == 0){
                ax = px[i].first;
                break;
            }
        }
        for(; i < n; i++){
            if(px[i].first > ax && d[px[i].second][0] == 0){
                f = false;
            }
        }
        i = 0;
        int ay = 100000;
        for(; i < n; i++){
            if(d[py[i].second][1] == 0){
                ay = py[i].first;
                break;
            }
        }
        for(; i < n; i++){
            if(py[i].first > ay && d[py[i].second][3] == 0){
                f = false;
            }
        }
        if(!f) cout << 0 << endl;
        else cout << 1 << " " << ax << " " << ay << endl;
    }
}