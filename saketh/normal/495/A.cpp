#include <iostream>
using namespace std;

int m[10] = {2, 7, 2, 3, 3, 4, 2, 5, 1, 2};

int main(){
    int N; cin >> N;
    cout << m[N/10] * m[N%10] << endl;
}