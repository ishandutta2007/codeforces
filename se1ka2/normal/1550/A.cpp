#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int s;
        cin >> s;
        int c = 0;
        for(int i = 1; i <= s; i++){
            c += i * 2 - 1;
            if(c >= s){
                cout << i << endl;
                break;
            }
        }
    }
}