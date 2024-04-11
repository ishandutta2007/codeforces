#include <bits/stdc++.h>
using namespace std;

int main(){
    int res = 1;
    int n;
    cin >> n;
    for(int i = 1; i < n; i++){
        res += 12 * i;
    }
    cout << res;
}