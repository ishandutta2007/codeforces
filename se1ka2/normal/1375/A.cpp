#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[102];
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(i % 2) a[i] = -abs(a[i]);
            else a[i] = abs(a[i]);
            cout << a[i] << " ";
        }
        cout << endl;
    }
}