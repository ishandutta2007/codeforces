#include <iostream>
using namespace std;

int main()
{
    int n, t, k;
    cin >> n >> t >> k;
    int left = 0, right = n;
    while(right - left > 1){
        int mid = (right + left) / 2;
        cout << "? 1 " << mid << endl;
        int c;
        cin >> c;
        if(mid - c < k) left = mid;
        else right = mid;
    }
    cout << "! " << right << endl;
}