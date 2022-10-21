#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int a, b, c;

int main(){
    cin >> a >> b >> c;
    int res = 6;
    for(int x = 1; x <= a; x++){
        if(x <= a && x + 1 <= b && x + 2 <= c) res = max(res, 3 * x + 3);
    }
    cout << res << endl;
}