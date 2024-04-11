#include <iostream>
using namespace std;

int main()
{
    int l, r;
    cin >> l >> r;
    for(int i = l; i <= r; i++){
        int num = i;
        bool d[10];
        bool f = true;
        fill(d, d + 10, false);
        while(num > 0){
            if(d[num % 10] == true){
                f = false;
                break;
            }
            d[num % 10] = true;
            num /= 10;
        }
        if(f){
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}