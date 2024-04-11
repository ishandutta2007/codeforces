#include<iostream>
using namespace std;

long long N, M, A;

int main(){
    cin >> N >> M >> A;
    long long n = N/A + ((N%A)?1:0);
    long long m = M/A + ((M%A)?1:0);
    cout << n*m << endl;
}