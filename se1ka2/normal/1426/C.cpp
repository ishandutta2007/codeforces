#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++){
            if(i * i >= n){
                cout << i * 2 - 2 << endl;
                break;
            }
            if((i + 1) * i >= n){
                cout << i * 2 - 1 << endl;
                break;
            }
        }
    }
}