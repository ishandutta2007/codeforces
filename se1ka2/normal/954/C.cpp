#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[200005];
    for(int i = 0; i < n; i++) cin >> a[i];
    int d = -1;
    for(int i = 1; i < n; i++){
        if(abs(a[i] - a[i - 1]) != 1){
            d = abs(a[i] - a[i - 1]);
            break;
        }
    }
    if(d == -1){
        cout << "YES" << endl;
        cout << "1000000000 1000000000" << endl;
        return 0;
    }
    if(d == 0){
        cout << "NO" << endl;
        return 0;
    }
    for(int i = 1; i < n; i++){
        if(abs(a[i] - a[i - 1]) != 1 && abs(a[i] - a[i - 1]) != d){
            cout << "NO" << endl;
            return 0;
        }
        if((a[i] % d == 0 && a[i - 1] == a[i] + 1) || (a[i - 1] % d == 0 && a[i] == a[i - 1] + 1)){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    cout << "1000000000 " << d << endl;
}