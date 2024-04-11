#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        int x, y, z;
        cin >> x >> y >> z;
        cout << min(z + 1, max(0, (x + z + 1 - y) / 2)) << endl;
    }
}