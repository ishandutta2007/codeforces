#include <iostream>
using namespace std;
int main(){
    long long n;
    cin >> n;
    if(n%2 == 0){
        cout << n/2 << endl;
        return 0;
    }
    cout << (n/2)*(-1)-1 << endl;
    return 0;
}