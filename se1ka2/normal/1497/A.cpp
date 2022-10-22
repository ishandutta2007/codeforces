#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int b[102]{0};
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            b[a]++;
        }
        for(int i = 0; i < n; i++){
            if(b[i]){
                cout << i << " ";
                b[i]--;
            }
            else break;
        }
        for(int i = 0; i <= 100; i++){
            for(int j = 0; j < b[i]; j++) cout << i << " ";
        }
        cout << endl;
    }
}