#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

int main(){
    ll N, K;
    cin >> N >> K;

    ll nextPow = 1;
    ll powNum = 1;
    while(nextPow < N){
        nextPow*=2;
        nextPow++;
        powNum++;
    }
    if(K == 1){
        cout << N;
    } else{
        cout << nextPow;
    }
    /*if(powNum <= K){
        cout << nextPow;
        return 0;
    }*/

    //will the next number of 111111..111 ever be unobtainable except when K=1? i dont think so!

    //cout << "oop";
    return 0;
}