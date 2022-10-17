#include <iostream>
#include <vector>
using namespace std;

int N, M, K;
vector<pair<int, int> > cells;

int main(){
    cin >> N >> M >> K;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            cells.emplace_back(i, (i&1)?(M-1-j):j);

    for(int t=0; t<K; t++){
        if(t+1==K) cout << N*M - 2*(K-1) << " ";
        else cout << "2 ";
        for(int i=2*t; i<((t+1==K)?(N*M):(2*(t+1))); i++)
           cout << cells[i].first+1 << " " << cells[i].second+1 << " ";
        cout << "\n";
    }

    cout.flush();
    return 0;
}