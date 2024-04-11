#include<iostream>
#include<algorithm>
using namespace std;

int N, K;
int v[105];

int main(){
    cin >> N >> K;
    for(int i=0; i<N; i++)
        cin >> v[i];
    sort(v, v+N);
    cout << v[N-K] << endl;
    return 0;
}