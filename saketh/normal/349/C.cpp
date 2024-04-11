#include <iostream>
using namespace std;

typedef long long ll;

ll N, v[100005], m, s;

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> v[i];
        m = max(m, v[i]);
        s += v[i];
    }

    cout << max(m, (s+N-2)/(N-1)) << endl;
    return 0;
}