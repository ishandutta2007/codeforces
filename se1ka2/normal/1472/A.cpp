#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int h, w, n;
        cin >> h >> w >> n;
        int k = 1;
        while(h % 2 == 0){
            k *= 2;
            h /= 2;
        }
        while(w % 2 == 0){
            k *= 2;
            w /= 2;
        }
        if(k >= n) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}