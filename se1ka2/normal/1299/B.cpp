#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if(n % 2){
        cout << "NO" << endl;
        return 0;
    }
    int x[100002], y[100002];
    for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
    for(int i = 0; i < n / 2; i++){
        if(x[i] - x[i + 1] != x[(i + n / 2 + 1) % n] - x[i + n / 2] || y[i] - y[i + 1] != y[(i + n / 2 + 1) % n] - y[i + n / 2]){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}