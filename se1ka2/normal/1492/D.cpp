#include <iostream>
using namespace std;

int main()
{
    int a, b, k;
    cin >> a >> b >> k;
    if(a == 0){
        if(k == 0){
            cout << "Yes" << endl;
            for(int i = 0; i < b; i++) cout << 1;
            cout << endl;
            for(int i = 0; i < b; i++) cout << 1;
            cout << endl;
        }
        else{
            cout << "No" << endl;
        }
        return 0;
    }
    if(b == 1){
        if(k == 0){
            cout << "Yes" << endl;
            cout << 1;
            for(int i = 0; i < a; i++) cout << 0;
            cout << endl;
            cout << 1;
            for(int i = 0; i < a; i++) cout << 0;
            cout << endl;
        }
        else{
            cout << "No" << endl;
        }
        return 0;
    }
    if(k > a + b - 2){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    for(int i = 0; i < b; i++) cout << 1;
    for(int i = 0; i < a; i++) cout << 0;
    cout << endl;
    if(k < b){
        for(int i = 0; i < b - k; i++) cout << 1;
        cout << 0;
        for(int i = b - k; i < b; i++) cout << 1;
        for(int i = 1; i < a; i++) cout << 0;
    }
    else{
        cout << 10;
        for(int i = 1; i < b - 1; i++) cout << 1;
        for(int i = 1; i < k - b + 2; i++) cout << 0;
        cout << 1;
        for(int i = k - b + 2; i < a; i++) cout << 0;
    }
    cout << endl;
}