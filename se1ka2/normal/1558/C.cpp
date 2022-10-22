#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[2030];
        for(int i = 0; i < n; i++){
            cin >> a[i];
            a[i]--;
        }
        bool f = true;
        for(int i = 0; i < n; i++){
            if((a[i] + i) % 2) f = false;
        }
        if(!f){
            cout << -1 << endl;
            continue;
        }
        cout << n / 2 * 5 << endl;
        for(int i = n; i >= 3; i -= 2){
            for(int j = 0; j < i; j++){
                if(a[j] == i - 1){
                    cout << j + 1 << " ";
                    reverse(a, a + j + 1);
                    break;
                }
            }
            for(int j = 0; j < i; j++){
                if(a[j] == i - 2){
                    cout << j << " ";
                    reverse(a, a + j);
                    cout << j + 2 << " ";
                    reverse(a, a + j + 2);
                    cout << 3 << " ";
                    swap(a[0], a[2]);
                    cout << i << " ";
                    reverse(a, a + i);
                    break;
                }
            }
        }
        cout << endl;
    }
}