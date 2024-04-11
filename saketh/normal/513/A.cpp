#include <iostream>
using namespace std;

int N1, N2, K1, K2;

int main(){
    cin >> N1 >> N2 >> K1 >> K2;

    if(N1 <= N2) cout << "Second" << endl;
    else cout << "First" << endl;
}