#include <iostream>

using namespace std;

int main()
{
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    cout << 50 << " " << 50 << endl;
    for(int i=0;i<50;i++){
        for(int j=0;j<50;j++){
        if(i%2 ==0 && j%2 == 0 && i<25 && j<25 && a>1){
            cout << 'A';
            a--;
        }
        else if(i<25 && j<25){
            cout << 'D';
        }
        else if(i%2 ==0 && j%2 == 0 && i<25 && j>=25 && b>1){
            cout << 'B';
            b--;
        }
        else if( i<25 && j>=25){
            cout << 'C';
        }
        else if(i%2 ==0 && j%2 == 0 && i>=25 && j<25 && c>1){
            cout << 'C';
            c--;
        }
        else if(i>=25 && j<25){
            cout << 'B';
        }
        else if(i%2 ==0 && j%2 == 0 && i>=25 && j>=25 && d>1){
            cout << 'D';
            d--;
        }
        else if(i>=25 && j>=25){
            cout << 'A';
        }
    }
    cout << endl;
    }
    return 0;
}