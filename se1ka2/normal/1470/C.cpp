#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    if(n <= 900){
        for(int i = 0; i < n; i++){
            cout << "? 1" << endl;
            int c;
            cin >> c;
            if(c < k){
                cout << "! " << i % n + 1 << endl;
                return 0;
            }
            if(c > k){
                cout << "! " << (n - i) % n + 1 << endl;
                return 0;
            }
        }
        cout << "? 2" << endl;
        int c;
        cin >> c;
        if(c < k) cout << "! " << n / 2 + 1 << endl;
        else cout << "! 1" << endl;
        return 0;
    }
    int l;
    for(l = 0; l * l < n; l++){
        cout << "? 1" << endl;
        int c;
        cin >> c;
        if(c < k){
            cout << "! " << l % n + 1 << endl;
            return 0;
        }
        if(c > k){
            cout << "! " << (n - l) % n + 1 << endl;
            return 0;
        }
    }
    for(int i = 0; i < n; i += l){
        cout << "? " << i + 1 << endl;
        int c;
        cin >> c;
        int left = -1, right = -1;
        if(c < k){
            left = i;
            right = i + l * 2;
        }
        if(c > k){
            left = i - l * 2 + n;
            right = i + n;
        }
        if(left == -1 && right == -1) continue;
        while(right - left > 1){
            int mid = (right + left) / 2;
            cout << "? " << mid % n + 1 << endl;
            int c;
            cin >> c;
            if(c == k){
                cout << "! " << mid % n + 1 << endl;
                return 0;
            }
            if(c < k) left = mid;
            else right = mid;
        }
        cout << "! " << right % n + 1 << endl;
        return 0;
    }
}