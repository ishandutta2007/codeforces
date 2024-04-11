#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        int c = abs(a - b);
        cout << (c + 9) / 10 << endl;
    }
}