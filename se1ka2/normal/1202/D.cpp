#include <iostream>
using namespace std;
const int p = 50000;

int main()
{
    int s[p] {0};
    for(int i = 1; i < p; i++) s[i] = s[i - 1] + i;
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        int n;
        cin >> n;
        for(int i = p - 1; i > 0; i--){
            for(int j = 0; j < n / s[i]; j++) cout << 1;
            n %= s[i];
            cout << 3;
        }
        cout << 37 << endl;
    }
}