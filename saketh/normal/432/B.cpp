#include <iostream>
#include <map>
using namespace std;

int N;
int hc[100005], ac[100005];
map<int, int> hcc, acc;

int main(){
    ios_base::sync_with_stdio(false);

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> hc[i] >> ac[i];
        hcc[hc[i]]++;
        acc[ac[i]]++;
    }

    for(int i=0; i<N; i++){
        int hm = N-1 + hcc[ac[i]];
        cout << hm << " " << (2*N-2-hm) << "\n";
    }

    cout.flush();
    return 0;
}