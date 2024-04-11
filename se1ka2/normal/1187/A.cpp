#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n, s, t;
        cin >> n >> s >> t;
        int d = s + t - n;
        s -= d;
        t -= d;
        cout << max(s, t) + 1 << endl;
    }
}