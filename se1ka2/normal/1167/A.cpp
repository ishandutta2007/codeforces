#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        int n;
        cin >> n;
        string s;
        cin >> s;
        bool f = false;
        for(int i = 0; i < n - 10; i++){
            if(s[i] == '8'){
                cout << "YES" << endl;
                f = true;
                break;
            }
        }
        if(!f) cout << "NO" << endl;
    }
}