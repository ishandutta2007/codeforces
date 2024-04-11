#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[1002];
        for(int i = 0; i < n; i++) cin >> a[i];
        cout << n * 3 << endl;
        for(int i = 0; i < n; i += 2){
            cout << 1 << " " << i + 1 << " " << i + 2 << endl;
            cout << 2 << " " << i + 1 << " " << i + 2 << endl;
            cout << 1 << " " << i + 1 << " " << i + 2 << endl;
            cout << 1 << " " << i + 1 << " " << i + 2 << endl;
            cout << 2 << " " << i + 1 << " " << i + 2 << endl;
            cout << 1 << " " << i + 1 << " " << i + 2 << endl;
        }
    }
}