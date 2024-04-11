#include <iostream>
using namespace std;

int N, M, v[105], G;

int main(){
    cin >> N >> M;
    for(int i=0; i<N; i++)
        cin >> v[i];

    for(int L = N; L; ){
        for(int i=0; i<N; i++)
            if(v[i] > 0){
                v[i] -= M;
                if(v[i] <= 0){
                    G = i;
                    L--;
                }
            }
    }

    cout << G+1 << endl;
    return 0;
}