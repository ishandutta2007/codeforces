#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int w = 0; w < t; w++){
        string a, b, c;
        cin >> a >> b >> c;
        int n = a.size();
        int i = 0;
        for(; i < n; i++){
            if(c[i] != a[i] && c[i] != b[i]) break;
        }
        if(i == n) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}