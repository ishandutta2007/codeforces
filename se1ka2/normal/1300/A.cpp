#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        int n;
        cin >> n;
        int a[102];
        int z = 0, s = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(a[i] == 0){
                z++;
                s++;
            }
            s += a[i];
        }
        if(s == 0) z++;
        cout << z << endl;
    }
}