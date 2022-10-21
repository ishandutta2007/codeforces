#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    cin >> a >> b;
    int n = (a % 2 == 0 ? (a/2*a/2):(a/2*((a/2)+1))); a = b;
    int m = (a % 2 == 0 ? (a/2*a/2):(a/2*((a/2)+1)));
    cout << (long long)n * m;
}