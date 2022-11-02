#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int x = 0;
    for(int i = 1; i < n; i ++) {
        x += i;
        printf("%d ", x % n + 1);
    }
    puts("");
}