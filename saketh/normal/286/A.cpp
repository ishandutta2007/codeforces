#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> v;

void dog(int a, int b, int c, int d){
    v[a-1] = b;
    v[b-1] = d;
    v[d-1] = c;
    v[c-1] = a;
}

int main(){
    cin >> N;
    v.resize(N);

    if(N % 4 > 1){
        cout << -1 << endl;
        return 0;
    }

    if(N&1){
        int spc = N/2 + 1;
        v[spc-1] = spc;
    }

    int i = 1, j = N;
    while(j-i > 1){
        dog(i, i+1, j-1, j);
        i += 2;
        j -= 2;
    }

    for(int a : v) cout << a << " ";
    cout << endl;
}