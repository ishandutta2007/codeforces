#include <iostream>
#include <algorithm>
using namespace std;

int N, v[105];

int main(){
    cin >> N;
    for(int i=0; i<N; i++) cin >> v[i];
    sort(v, v+N);
    for(int i=0; i<N; i++) cout << v[i] << " ";
    cout << endl;
    return 0;
}