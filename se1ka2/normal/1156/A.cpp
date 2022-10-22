#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[103];
    for(int i = 0; i < n; i++) cin >> a[i];
    int ans = 0;
    for(int i = 1; i < n; i++){
        if(a[i - 1] == 1){
            if(a[i] == 2){
                if(i == 1 || a[i - 2] == 2) ans += 3;
                else ans += 2;
            }
            else ans += 4;
        }
        else if(a[i - 1] == 2){
            if(a[i] == 1) ans += 3;
            else{
                cout << "Infinite" << endl;
                return 0;
            }
        }
        else{
            if(a[i] == 1) ans += 4;
            else{
                cout << "Infinite" << endl;
                return 0;
            }
        }
    }
    cout << "Finite" << endl;
    cout << ans << endl;
}