#include<iostream>
using namespace std;

long long N, T, A, B, R;

int main(){
    cin >> N;
    for(int n=0; n<N; n++){
        cin >> B;
        if(R>0 && B == A) R++;
        else if(R>0){
            A = B;
            T += R + R*(R-1)/2;
            R = 1;
        }
        else{
            R = 1;
            A = B;
        }
    }
    cout << T + R + R*(R-1)/2 << endl;
}