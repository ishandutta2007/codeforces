#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int x1 = 1, y1 = 1; 
    int x2 = 1, y2 = 2;
    for(int c = 0; c < n * n; c++){
        int a;
        cin >> a;
        if(a == 1){
            if(x2 <= n){
                cout << 2 << " " << x2 << " " << y2 << endl;
                y2 += 2;
                if(y2 > n){
                    x2++;
                    y2 = x2 % 2 + 1;
                }
            }
            else{
                cout << 3 << " " << x1 << " " << y1 << endl;
                y1 += 2;
                if(y1 > n){
                    x1++;
                    y1 = (x1 + 1) % 2 + 1;
                }
            }
        }
        if(a == 2){
            if(x1 <= n){
                cout << 1 << " " << x1 << " " << y1 << endl;
                y1 += 2;
                if(y1 > n){
                    x1++;
                    y1 = (x1 + 1) % 2 + 1;
                }
            }
            else{
                cout << 3 << " " << x2 << " " << y2 << endl;
                y2 += 2;
                if(y2 > n){
                    x2++;
                    y2 = x2 % 2 + 1;
                }
            }
        }
        if(a == 3){
            if(x1 <= n){
                cout << 1 << " " << x1 << " " << y1 << endl;
                y1 += 2;
                if(y1 > n){
                    x1++;
                    y1 = (x1 + 1) % 2 + 1;
                }
            }
            else{
                cout << 2 << " " << x2 << " " << y2 << endl;
                y2 += 2;
                if(y2 > n){
                    x2++;
                    y2 = x2 % 2 + 1;
                }
            }
        }
    }
    cout << endl;
}