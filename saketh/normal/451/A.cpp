#include <iostream>
using namespace std;

int N, M;

int main(){
    cin >> N >> M;
    int sum = min(N, M);

    cout << ((sum%2)?"Akshat":"Malvika") << endl;
    return 0;
}