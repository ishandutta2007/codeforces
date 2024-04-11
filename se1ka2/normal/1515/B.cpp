#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n % 2){
            cout << "NO" << endl;
            continue;
        }
        while(n % 2 == 0) n /= 2;
        int right = 40000, left = 0;
        while(right - left > 1){
            int mid = (right + left) / 2;
            if(mid * mid >= n) right = mid;
            else left = mid;
        }
        if(right * right == n) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}