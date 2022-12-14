#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        if(360 % (180-t) == 0){
            cout << "YES";
        }else{
            cout << "NO";
        }
        cout << endl;
    }
    return 0;
}