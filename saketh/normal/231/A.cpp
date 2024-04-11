#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    int s = 0;
    for (int i = 0; i < N; i++) {
        int a, b, c; 
        cin >> a >> b >> c; 
        if (a+ b + c > 1) s++;
    }

    cout << s << "\n";
}