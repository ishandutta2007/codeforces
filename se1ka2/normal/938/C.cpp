#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int x;
        cin >> x;
        if(x == 0){
            cout << "1 1" << endl;
            continue;
        }
        bool f = false;
        for(int i = 1; i * i <= x; i++){
            if(x % i == 0){
                if(i % 2 != (x / i) % 2) continue;
                int l = (x / i - (i - 1)) / 2;
                int r = l + i;
                if(l >= 1 && r / (r / l) == l){
                    cout << r << " " << r / l << endl;
                    f = true;
                    break;
                }
            }
        }
        if(!f) cout << -1 << endl;
    }
}