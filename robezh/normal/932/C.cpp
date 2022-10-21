#include <bits/stdc++.h>
using namespace std;

int n,a,b,x,y;

bool set_a_b(){
    for(int i = 0; i <= n/x; i++){
        if((n-i*x) % y == 0){
            a = i;
            b = (n-i*x)/y;
            return true;
        }
    }
    return false;
}

int main(){
    cin >> n >> x >> y;
    if(!set_a_b()) return !printf("-1");
    for(int i = 1; i <= a * x; i++){
        if(i % x == 0) cout << i+1-x << " ";
        else cout << i+1 << " ";
    }
    for(int i = a * x + 1; i <= n; i++){
        int k = i - a * x;

        if(k % y == 0) cout << i+1-y << " ";
        else cout << i+1 << " ";
    }
}