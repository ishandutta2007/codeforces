#include <queue>
#include <iostream>
using namespace std;

int N, M;
int cost[1005];

int main(){
    cin >> N >> M;
    
    for(int i=0; i<N; i++)
        cin >> cost[i];
    
    int tot = 0;
    
    for(int i=0; i<M; i++){
        int A, B;
        cin >> A >> B;
        tot += min( cost[A-1], cost[B-1] );
    }
    
    cout << tot << endl;

    return 0;
}