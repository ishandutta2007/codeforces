#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[10005];
        for(int i = 0; i < n; i++) cin >> a[i];
        a[n] = 1;
        for(int i = 0; i <= n; i++){
            if(a[i] == 1){
                for(int j = 0; j < i; j++) cout << j + 1 << " ";
                cout << n + 1;
                for(int j = i; j < n; j++) cout << " " << j + 1;
                cout << endl;
                break;
            }
        }
    }
}