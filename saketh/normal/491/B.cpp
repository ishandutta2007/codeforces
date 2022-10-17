#include <iostream>
#include <algorithm>
#define INF 1LL<<50
using namespace std;

int N; long long x, y;
long long v[4] = {INF, -INF, INF, -INF};

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N >> N >> N;
    for(int i=0; i<N; i++){
        cin >> x >> y;
        v[0] = min(v[0], x+y);
        v[1] = max(v[1], x+y);
        v[2] = min(v[2], x-y);
        v[3] = max(v[3], x-y);
    }

    long long a = INF, j = -1;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> x >> y;
        long long d = max( max( abs(x+y - v[0]), abs(x+y - v[1])),
                     max( abs(x-y - v[2]), abs(x-y - v[3])));
        if(d < a){
            a = d;
            j = i;
        } 
    }

    cout << a << "\n" << j+1 << endl;
    return 0;
}