#include <iostream>
#include <algorithm>
using namespace std;

int N, v[4], u[4];

bool ok(){
    int j = 0;
    for(int i=0; i<4; i++)
        if(j<N && u[i]==v[j]) j++;
    return j==N;
}

void print(){
    cout << "YES" << endl;

    int j = 0;
    for(int i=0; i<4; i++){
        if(j<N && u[i]==v[j]) j++;
        else cout << u[i] << endl;
    }
}

int main(){
    cin >> N;
    for(int i=0; i<N; i++)
        cin >> v[i];

    sort(v, v+N);

    for(int x=1; x<=500; x++)
        for(int c=0; c<=500; c++){
            if(2*x-c < x) continue;
            u[0] = x, u[1] = 2*x-c, u[2] = 2*x+c, u[3] = 3*x;
            if(ok()){
                print();
                return 0;
            }
        }

    cout << "NO" << endl;
    return 0;
}