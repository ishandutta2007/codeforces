#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cout << "? 1 " << n << endl;
    int c;
    cin >> c;
    int d;
    if(c > 1){
        cout << "? 1 " << c << endl;
        cin >> d;
        if(c == d){
            int left = 1, right = c;
            while(right - left > 1){
                int mid = (right + left) / 2;
                cout << "? " << mid << " " << c << endl;
                int t;
                cin >> t;
                if(t == c) left = mid;
                else right = mid;
            }
            cout << "! " << left << endl;
            return 0;
        }
    }
    int left = c, right = n;
    while(right - left > 1){
        int mid = (right + left) / 2;
        cout << "? " << c << " " << mid << endl;
        int t;
        cin >> t;
        if(t == c) right = mid;
        else left = mid;
    }
    cout << "! " << right << endl;
}