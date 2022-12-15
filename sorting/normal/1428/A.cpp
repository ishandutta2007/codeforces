#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int d = abs(x1 - x2) + abs(y1 - y2);
        if(x1 != x2 && y1 != y2) d += 2;
        cout << d << "\n";       
    }
}