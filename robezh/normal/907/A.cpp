#include <bits/stdc++.h>
using namespace std;

int v1, v2, v3, vm;

bool can(int v, int c){
    return v <= c;
}

bool like(int v, int c){
    return 2 * v >= c;
}

bool both(int v, int c){
    return can(v,c) && like(v,c);
}

bool check(int a, int b, int c){
    return both(v1,a) && both(v2,b) && both(v3,c) && vm <= c && like(vm,c) && !like(vm,b);
}


int main() {
    cin >> v1 >> v2 >> v3 >> vm;
    for(int a = 220; a >= 0; a--){
        for(int b = a-1; b >= 0; b--){
            for(int c = b-1; c >= 0; c--){
                if(check(a,b,c)) return !printf("%d\n%d\n%d\n",a,b,c);
            }
        }
    }
    printf("-1");

}