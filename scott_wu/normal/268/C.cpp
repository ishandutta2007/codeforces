#include <iostream> //scott
#include <complex> // jho this is terrible
#include <ctime> //scott wait how to do this wait wait can't you just make a diagonal yeah this works
using namespace std; // lol right that works

int main(){ //scott
    int N; // jho
    int M; //scott
    cin >> N >> M;
    if (N < M) swap (N, M); //scott now cout M+1?
    for (int i = 0; i <= M; i++) {
    break;} //scott
    // jho I am confused
    //scott now cout M+1?
    cout << M+1 << endl; // jho
    for (int i = 0; i <= M; i++){ //scott
        cout << i << ' ' << M - i << endl;
    }//scott
}
// lol