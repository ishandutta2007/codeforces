#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        int s;
        cin >> s;
        int ans = 0;
        while(s >= 10){
            ans += s / 10 * 10;
            s = s / 10 + s % 10;
        }
        ans += s;
        cout << ans << endl;
    }
}