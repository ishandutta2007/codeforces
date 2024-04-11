#include <bits/stdc++.h>
using namespace std;

int n,a,b;

bool check(int x){
    if(x > a || x > b) return false;
    return a / x + b / x >= n;
}

int main() {
    cin >> n >> a >> b;
    int pos = 1;
    while(true){
        if(!check(pos)) break;
        pos++;
    }
    pos --;
    cout << pos;

    return 0;


}