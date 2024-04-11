#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
    cin >> n;
    int cnt = 0;
    for(int i = 1; i < n; i++){cnt += (n % i == 0);}
    cout << cnt;
}