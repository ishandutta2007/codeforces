#include <iostream>
#include <unordered_map>
using namespace std;

typedef long long ll;

ll N, M, DX, DY, X, Y;
unordered_map<ll, int> apples;

int main(){
    int b = 0, x = 0, y = 0;
    cin >> N >> M >> DX >> DY;
    for(int i=0; i<M; i++){
        cin >> X >> Y;

        ll key = (Y * DX - X * DY) % N;
        if(key < 0) key += N;

        apples[key]++;

        if(apples[key] > b){
            b = apples[key];
            x = X;
            y = Y;
        }
    }

    cout << x << " " << y << endl;
}