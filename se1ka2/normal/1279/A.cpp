#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int w = 0; w < t; w++){
        int c[3];
        for(int i = 0; i < 3; i++) cin >> c[i];
        sort(c, c + 3, greater<int>());
        if(c[0] > c[1] + c[2] + 1) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
}