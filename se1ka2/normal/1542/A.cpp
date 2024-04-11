#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int c = 0;
        for(int i = 0; i < n * 2; i++){
            int a;
            cin >> a;
            c += a % 2;
        }
        if(c == n) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}