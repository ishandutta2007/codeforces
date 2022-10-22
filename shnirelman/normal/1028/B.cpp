#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++)cout << '1';
    cout << endl;
    for(int i = 0; i < n - 1; i++)cout << '8';
    cout << '9';
}