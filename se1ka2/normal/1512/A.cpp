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
        int b[102]{0};
        for(int i = 0; i < n; i++){
            cin >> a[i];
            b[a[i]]++;
        }
        for(int i = 0; i < n; i++){
            if(b[a[i]] == 1){
                cout << i + 1 << endl;
            }
        }
    }
}