#include <iostream>
using namespace std;

int main()
{
    int a[4];
    int sum = 0;
    for(int i = 0; i < 4; i++){
        cin >> a[i];
        sum += a[i];
    }
    for(int i = 0; i < (1 << 4); i++){
        int now = 0;
        for(int j = 0; j < 4; j++){
            if((i >> j) & 1){
                now += a[j];
            }
        }
        if(now * 2 == sum){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}