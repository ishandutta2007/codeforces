#include <iostream>
using namespace std;

int N, M;

int main(){
    cin >> N >> M;

    double prob = 1.0 / N;
    if(N*M>1) prob += (N - 1.0) / N * (M - 1) / (N * M - 1);

    cout.precision(20);
    cout << prob << endl;
}