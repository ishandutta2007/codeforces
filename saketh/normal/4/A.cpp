#include<iostream>
using namespace std;

int W;

int main(){
    cin >> W;
    if(W%2 == 0 && W>2) cout << "YES" << endl;
    else cout << "NO" << endl;
}