#include <iostream> //scott math too hard wait no subtract (n)(n-1)/2 from that
using namespace std; // what the fuck okay

int main(){ //scott it works
    int N;
    cin >> N; //scott
    int tot = 0;// jho
    for (int i = 0; i < N; i++) tot += ((i+1) * (N - i)); //scott wait we might need ll uhh don't think so jk
    tot -= N * (N - 1) / 2; // jho
    cout << tot << "\n";
}