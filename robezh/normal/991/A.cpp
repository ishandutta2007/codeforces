#include <bits/stdc++.h>
using namespace std;

int a,b,c,n;

int main(){
    cin >> a >> b >> c >> n;
    int res = n - (a + b - c);
    if(c > a || c > b) res = -1;
    if(res < 1) res = -1;
    cout << res;
}