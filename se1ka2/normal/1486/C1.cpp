#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int left = 0, right = n;
    while(right - left > 3){
        int mid = (right + left) / 2;
        cout << "? " << left + 1 << " " << right << endl;
        int c;
        cin >> c;
        c--;
        if(c >= mid){
            cout << "? " << mid + 1 << " " << right << endl;
            int d;
            cin >> d;
            d--;
            if(d == c) left = mid;
            else right = mid;
        }
        else{
            cout << "? " << left + 1 << " " << mid << endl;
            int d;
            cin >> d;
            d--;
            if(d == c) right = mid;
            else left = mid;
        }
    }
    if(right - left == 3){
        int t[3];
        cout << "? " << left + 1 << " " << left + 3 << endl;
        cin >> t[0];
        cout << "? " << left + 1 << " " << left + 2 << endl;
        cin >> t[1];
        cout << "? " << left + 2 << " " << left + 3 << endl;
        cin >> t[2];
        for(int i = 1; i <= 3; i++){
            bool f = true;
            for(int j = 0; j < 3; j++){
                if(t[j] == left + i) f = false;
            }
            if(f) cout << "! " << left + i << endl;
        }
    }
    else if(right - left == 2){
        int t;
        cout << "? " << left + 1 << " " << left + 2 << endl;
        cin >> t;
        if(t == left + 1) cout << "! " << left + 2 << endl;
        else cout << "! " << left + 1 << endl;
    }
    else cout << "! " << right << endl;
}