#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 0; i < n - (n + 3) / 4; i++) cout << 9;
        for(int i = n - (n + 3) / 4; i < n; i++) cout << 8;
        cout << endl;
    }
}