#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i * 2 < n - 1; i++){
        for(int j = 0; j * 2 < n - 1; j++){
            cout << "WB";
        }
        if(n % 2) cout << "W";
        cout << endl;
        for(int j = 0; j * 2 < n - 1; j++){
            cout << "BW";
        }
        if(n % 2) cout << "B";
        cout << endl;
    }
    if(n % 2){
        for(int j = 0; j * 2 < n - 1; j++){
            cout << "WB";
        }
        cout << "W" << endl;
    }
}