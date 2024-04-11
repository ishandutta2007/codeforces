#include <iostream>
using namespace std;

int N, v[3005];

int main(){
    cin >> N;
    for(int i=0; i<N; i++)
        cin >> v[i];

    cout << N << "\n";
    for(int i=0; i<N; i++){
        int mv = v[i], mi = i;
        for(int j=i+1; j<N; j++)
            if(v[j] < mv){
                mv = v[j];
                mi = j;
            }

        swap(v[i], v[mi]);
        cout << i << " " << mi << "\n";
    }

    cout.flush();
    return 0;
}