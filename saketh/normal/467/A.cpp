#include <iostream>
using namespace std;

int N, A, X, Y;

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> X >> Y;
        if(X + 2 <= Y) A++;
    }

    cout << A << endl;
    return 0;
}