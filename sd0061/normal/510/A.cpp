#include <iostream>
using namespace std;

int main() {
    int n , m;
    cin >> n >> m;
    for (int i = 0 ; i < n ; ++ i) {
        if (~i & 1) {
            for (int j = 0 ; j < m ; ++ j)
                cout << '#';
        } else {
            if ((i & 3) == 1) {
                for (int j = 1 ; j < m ; ++ j)
                    cout << '.';
                cout << '#';
            } else {
                cout << '#';
                for (int j = 1 ; j < m ; ++ j)
                    cout << '.';
            }
        }
        cout << endl;
        
    }
}