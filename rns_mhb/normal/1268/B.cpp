#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    long long A = 0, B = 0;
    for(int i = 1; i <= n; i ++) {
        int x;
        scanf("%d", &x);
        if(i & 1) A += x>>1, B += x+1>>1;
        else B += x >> 1, A += x + 1 >>1;
    }
    cout << min(A, B) << endl;
}