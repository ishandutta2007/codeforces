#include <iostream>
using namespace std;

int n;

int main(){
    cin >> n;

    if(n % 2){
        int R = n % 3;
        if(R == 0) cout << 6 << " " << n-6 << endl;
        else if(R == 1) cout << 4 << " " << n-4 << endl;
        else cout << 8 << " " << n-8 << endl;
    }
    else cout << 4 << " " << n-4 << endl;
    return 0;
}