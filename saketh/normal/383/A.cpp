#include<iostream>
using namespace std;

int N, R, i;
long long A;

int main(){
    cin >> N;
    
    for(int r=0; r<N; r++){
        cin >> i;
        if(i == 1) R++;
        else A += R;
    }
    
    cout << A<< endl;
    return 0;
}