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
        bool f = true;
        for(int i = 0; i < n / 2; i++){
            if(abs(s[i] - s[n - 1 - i]) != 2 && abs(s[i] - s[n - 1 - i]) != 0){
                f = false;
                break;
            }
        }
        if(f) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}