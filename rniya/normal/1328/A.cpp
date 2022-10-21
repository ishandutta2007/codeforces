#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        int a,b; cin >> a >> b;
        cout << (a+b-1)/b*b-a << '\n';
    }
}