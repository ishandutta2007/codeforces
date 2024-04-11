#include <iostream>
using namespace std;

int A, B;

int main(){
    cin >> A >> B;

    for(int i=B+1; i<=A+B+1; i++)
        cout << i << " ";
    for(int i=B; i>=1; i--)
        cout << i << " ";
    cout << endl;
}