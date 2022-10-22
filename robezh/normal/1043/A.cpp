#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n;
int a[N];
int mxa = 0;

bool check(int k){
    int me = 0, other = 0;
    for(int i = 0; i < n; i++){
        other += a[i];
        me += k - a[i];
    }
    return me > other;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i], mxa = max(mxa, a[i]);
    for(int k = mxa; k <= 205; k++){
        if(check(k)) return !printf("%d", k);
    }
}