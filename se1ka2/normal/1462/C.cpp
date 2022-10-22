#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n > 45){
            cout << -1 << endl;
            continue;
        }
        string s;
        for(int i = 9; i > 0; i--){
            if(n >= i){
                s += char('0' + i);
                n -= i;
            }
        }
        reverse(s.begin(), s.end());
        cout << s << endl;
    }
}