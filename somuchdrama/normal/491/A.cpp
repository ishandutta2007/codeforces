#include <iostream>

using namespace std;

int main(){
    int n; cin >> n;
    int m; cin >> m;
    for(int i = m + 1; i <= n + m + 1; ++i) cout << i << ' ';
    for(int i = m; i > 0; --i) cout << i << ' ';
}