#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        string x, y;
        cin >> x >> y;
        int n = x.size(), m = y.size();
        int i = 0;
        for(; i < m; i++) if(y[m - 1 - i] == '1') break;
        for(int j = i; j < n; j++){
            if(x[n - 1 - j] == '1'){
                cout << j - i << endl;
                break;
            }
        }
    }
}