#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int w = 0; w < t; w++){
        int b, p, f;
        cin >> b >> p >> f;
        int h, c;
        cin >> h >> c;
        if(h > c){
            if(b < p * 2){
                cout << (b / 2) * h << endl;
            }
            else{
                cout << p * h + min((b - p * 2) / 2, f) * c << endl;
            }
        }
        else{
            if(b < f * 2){
                cout << (b / 2) * c << endl;
            }
            else{
                cout << f * c + min((b - f * 2) / 2, p) * h << endl;
            }
        }
    }
}