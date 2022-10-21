#include <bits/stdc++.h>
using namespace std;

bool check(int t, int x, int y){
    return y - x < t && x % t < y % t;
}

int main(){
    int n,a,b;
    int cn = 0;

    cin >> n >> a >> b;
    while(n > 0){
        n/=2;
        cn ++;
    }
    cn--;
    if(a > b){
        int tmp = a;
        a = b;
        b = tmp;
    }
    a--, b--;
    //cout << cn << endl;
    for(int i = 1; i <= cn; i++){
        //cout << (1 << i) << " " << a << " " << b << endl;
        if(check(1<<(i), a, b)){
            if(i == cn) return !printf("Final!");
            return !printf("%d", i);
        }
    }
}