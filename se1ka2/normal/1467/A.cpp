#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << 9;
        int l = 8;
        for(int i = 1; i < n; i++){
            cout << l;
            l = (l + 1) % 10;
        }
        cout << endl;
    }
}