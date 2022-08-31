#include <iostream>

using namespace std;

int main(){
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        cout << (n % 4 == 0 ? "YES" : "NO") << endl;
    }

    return 0;
}