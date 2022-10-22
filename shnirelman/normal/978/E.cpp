#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int inf = 10000000;

int main(){
    int n, w;
    cin >> n >> w;

    int s = 0;
    int smn = inf, smx = -inf;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        s += a;
        smn = min(s, smn);
        smx = max(s, smx);
    }

   // for(int i = max(0 - smn, 0); i + smx <= w; i++)cout << i << ' ';
    cout << max(min(w - smx, w) + 1 - max(0 - smn, 0), 0);
}