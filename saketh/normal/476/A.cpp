#include <iostream>
using namespace std;

int N, M;

int main(){
    cin >> N >> M;

    int mov = (N/2) + (N%2);
    int add = (M - (mov%M))%M;

    if(add > N/2){ cout << -1 << endl; return 0; }
    else cout << mov + add << endl;
}