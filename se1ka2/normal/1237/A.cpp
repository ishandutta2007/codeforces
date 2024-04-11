#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int e = 0;
    int a[20000];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(abs(a[i]) % 2 == 1) e++;
    }
    int f = 0;
    for(int i = 0; i < n; i++){
        if(abs(a[i]) % 2 == 1){
            if(f < e / 2){
                a[i]++;
                f++;
            }
            else a[i]--;
        }
        cout << a[i] / 2 << endl;
    }
}