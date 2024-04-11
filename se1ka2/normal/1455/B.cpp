#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int x;
        cin >> x;
        int s = 0;
        for(int i = 1; i <= x * 10; i++){
            s += i;
            if(s >= x && s - x != 1){
                cout << i << endl;
                break;
            }
        }
    }
}