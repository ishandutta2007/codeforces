#include <iostream>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int s1=1, s2=m;
    if (m == 1){
        for (int i = 1; i < (n + 1) / 2 + 1; i++){
            if (i != n + 1 - i){
                cout << i << ' ' << s1 << '\n';
            }
            cout << n + 1 - i << ' ' << s1 << '\n';
        }
    }
    if (m == 2){
        for (int i = 1; i <=n; i ++){
            cout << i << ' ' << s1 << '\n';
            cout << n + 1 - i << ' ' << s2 << '\n';
        }
    }
    if (m != 1 and m != 2) {
        while (abs(s1 - s2) > 1) {
            for (int i = 1; i <= n; i++) {
                cout << i << ' ' << s1 << '\n';
                cout << n + 1 - i << ' ' << s2 << '\n';
            }
            s1++;
            s2--;
        }
        if (m % 2 == 1) {
            for (int i = 1; i < (n + 1) / 2 + 1; i++) {
                if (i != n + 1 - i) {
                    cout << i << ' ' << s1 << '\n';
                }
                cout << n + 1 - i << ' ' << s1 << '\n';
            }
        }
        if (m % 2 == 0) {
            for (int i = 1; i <= n; i++) {
                cout << i << ' ' << s1 << '\n';
                cout << n + 1 - i << ' ' << s2 << '\n';
            }
        }
    }
    return 0;
}