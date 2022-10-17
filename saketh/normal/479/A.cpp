#include <iostream>
using namespace std;

int A, B, C;

int main(){
    cin >> A >> B >> C;

    int c1 = max(A * B, A + B) * C;
    int c2 = max(A * B, A + B) + C;
    int c3 = A + max(B * C, B + C);
    int c4 = A * max(B * C, B + C);

    cout << max(max(c1, c2), max(c3, c4)) << endl;
}