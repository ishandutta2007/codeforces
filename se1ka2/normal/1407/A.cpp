#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[1005];
        int c[2]{0};
        for(int i = 0; i < n; i++){
            cin >> a[i];
            c[a[i]]++;
        }
        if(c[0] >= c[1]){
            cout << c[0] << endl;
            for(int i = 0; i < c[0]; i++) cout << 0 << " ";
            cout << endl;
        }
        else if(c[0] < c[1]){
            cout << c[1] / 2 * 2 << endl;
            for(int i = 0; i < c[1] / 2 * 2; i++) cout << 1 << " ";
            cout << endl;
        }
    }
}