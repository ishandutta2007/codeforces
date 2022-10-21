#include <bits/stdc++.h>
using namespace std;

int n,m;
int a, b;

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++) cin >> a >> b;
    for(int i = 0; i < n; i++) cout << (i % 2 ? "0" : "1");
}