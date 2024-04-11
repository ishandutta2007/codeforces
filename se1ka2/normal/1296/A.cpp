#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        int n;
        cin >> n;
        int o = 0, e = 0;
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            if(a % 2) o++;
            else e++;
        }
        if(o != 0 && e != 0) cout << "YES" << endl;
        else if(o % 2) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}