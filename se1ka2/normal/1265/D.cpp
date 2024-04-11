#include <iostream>
using namespace std;

int main()
{
    int a[4];
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    if(a[0] + a[2] < a[1] + a[3]){
        if(a[0] + a[2] + 1 < a[1] + a[3]){
            cout << "NO" << endl;
            return 0;
        }
        if(a[3] > a[2]){
            if(a[0] == 0 && a[1] == 0){
                cout << "YES" << endl;
                for(int i = 0; i < a[2]; i++) cout << "3 2 ";
                cout << 3 << endl;
                return 0;
            }
            cout << "NO" << endl;
            return 0;
        }
        cout << "YES" << endl;
        for(int i = 0; i < a[3]; i++) cout << "3 2 ";
        a[2] -= a[3];
        for(int i = 0; i < a[2]; i++) cout << "1 2 ";
        for(int i = 0; i < a[0]; i++) cout << "1 0 ";
        cout << 1 << endl;
    }
    if(a[0] + a[2] > a[1] + a[3]){
        if(a[0] + a[2] > a[1] + a[3] + 1){
            cout << "NO" << endl;
            return 0;
        }
        if(a[0] > a[1]){
            if(a[2] == 0 && a[3] == 0){
                cout << "YES" << endl;
                for(int i = 0; i < a[1]; i++) cout << "0 1 ";
                cout << 0 << endl;
                return 0;
            }
            cout << "NO" << endl;
            return 0;
        }
        cout << "YES" << endl;
        for(int i = 0; i < a[0]; i++) cout << "0 1 ";
        a[1] -= a[0];
        for(int i = 0; i < a[1]; i++) cout << "2 1 ";
        for(int i = 0; i < a[3]; i++) cout << "2 3 ";
        cout << 2 << endl;
    }
    if(a[0] + a[2] == a[1] + a[3]){
        if(a[0] > a[1]){
            cout << "NO" << endl;
            return 0;
        }
        cout << "YES" << endl;
        for(int i = 0; i < a[0]; i++) cout << "0 1 ";
        a[1] -= a[0];
        for(int i = 0; i < a[1]; i++) cout << "2 1 ";
        for(int i = 0; i < a[3]; i++) cout << "2 3 ";
    }
}