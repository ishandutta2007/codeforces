#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    while(true){
        for(int i = 0; i < k; i++){
            cout << char('a' + i);
            n--;
            if(n == 0){
                cout << endl;
                return 0;
            }
            for(int j = i + 1; j < k; j++){
                cout << char('a' + i);
                n--;
                if(n == 0){
                    cout << endl;
                    return 0;
                }
                cout << char('a' + j);
                n--;
                if(n == 0){
                    cout << endl;
                    return 0;
                }
            }
        }
    }
}