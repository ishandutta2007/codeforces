#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[100005];
        int x = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            x ^= a[i];
        }
        int l;
        for(l = 30; l >= 0; l--){
            if((x >> l) & 1){
                break;
            }
        }
        if(l == -1){
            cout << "DRAW" << endl;
            continue;
        }
        int c = 0;
        for(int i = 0; i < n; i++){
            if((a[i] >> l) & 1){
                c++;
            }
        }
        if(c % 4 == 1){
            cout << "WIN" << endl;
        }
        else{
            if((n - c) % 2){
                cout << "WIN" << endl;
            }
            else{
                cout << "LOSE" << endl;
            }
        }
    }
}