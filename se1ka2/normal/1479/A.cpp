#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if(n == 1){
        cout << "! 1" << endl;
        return 0;
    }
    int a[100005];
    cout << "? 1" << endl;
    cin >> a[0];
    cout << "? 2" << endl;
    cin >> a[1];
    if(a[1] > a[0]){
        cout << "! 1" << endl;
        return 0;
    }
    cout << "? " << n << endl;
    cin >> a[n - 1];
    cout << "? " << n - 1 << endl;
    cin >> a[n - 2];
    if(a[n - 2] > a[n - 1]){
        cout << "! " << n << endl;
        return 0;
    }
    int left = 0, right = n - 1;
    while(right - left > 1){
        int mid = (right + left) / 2;
        for(int i = mid - 1; i <= mid + 1; i++){
            cout << "? " << i + 1 << endl;
            cin >> a[i];
        }
        if(a[mid] < a[mid - 1] && a[mid] < a[mid + 1]){
            cout << "! " << mid + 1 << endl;
            return 0;
        }
        if(a[mid - 1] < a[mid]) right = mid;
        else left = mid;
    }
}