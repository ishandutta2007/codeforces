#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int s = 0;
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            s += a;
        }
        if(s == n) cout << 0 << endl;
        else if(s < n) cout << 1 << endl;
        else cout << s - n << endl;
    }
}