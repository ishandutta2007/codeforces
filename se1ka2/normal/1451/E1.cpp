#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int c[2];
    cout << "XOR 1 2" << endl;
    cin >> c[0];
    cout << "XOR 2 3" << endl;
    cin >> c[1];
    int d[3];
    for(int i = 0; i < 3; i++){
        cout << "OR" << " " << i + 1 << " " << (i + 1) % 3 + 1 << endl;
        cin >> d[i];
    }
    int a[70000];
    for(int i = 0; i < 16; i++){
        if((c[0] >> i) & 1){
            if((c[1] >> i) & 1){
                if((d[2] >> i) & 1){
                    a[0] += (1 << i);
                    a[2] += (1 << i);
                }
                else{
                    a[1] += (1 << i);
                }
            }
            else{
                if((d[1] >> i) & 1){
                    a[1] += (1 << i);
                    a[2] += (1 << i);
                }
                else{
                    a[0] += (1 << i);
                }
            }
        }
        else{
            if((c[1] >> i) & 1){
                if((d[0] >> i) & 1){
                    a[0] += (1 << i);
                    a[1] += (1 << i);
                }
                else{
                    a[2] += (1 << i);
                }
            }
            else{
                if((d[0] >> i) & 1){
                    a[0] += (1 << i);
                    a[1] += (1 << i);
                    a[2] += (1 << i);
                }
            }
        }
    }
    for(int i = 3; i < n; i++){
        int t;
        cout << "XOR 1 " << i + 1 << endl;
        cin >> t;
        a[i] = t ^ a[0];
    }
    cout << "!";
    for(int i = 0; i < n; i++) cout << " " << a[i];
    cout << endl;
}