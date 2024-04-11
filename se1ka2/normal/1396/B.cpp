#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int l = 0;
        int s = 0;
        int a[102];
        for(int i = 0; i < n; i++){
            cin >> a[i];
            l = max(l, a[i]);
            s += a[i];
        }
        if(l * 2 > s){
            cout << "T" << endl;
        }
        else if(s % 2){
            cout << "T" << endl;
        }
        else{
            cout << "HL" << endl;
        }
    }
}