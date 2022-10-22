#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int a[4];
        for(int i = 0; i < 4; i++) cin >> a[i];
        cout << max(a[0] + a[1], a[2] + a[3]) << endl;
    }
}