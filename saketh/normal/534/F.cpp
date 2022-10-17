#include <iostream>
#include <tuple>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <random>
#include <chrono>
using namespace std;

int pow10[5] = {1, 10, 100, 1000, 10000};
int N, M;
vector<int> rows, cols;
vector<int> valr[20], valc[5];

int count_blocks(int mask){
    if(mask == 0) return 0;
    while((mask&1) == 0) mask >>= 1;
    while((mask&1) == 1) mask >>= 1;
    return 1 + count_blocks(mask); 
}

int grid[5];
bool can_fin[5][32][5];

void search(int dep){
    if(dep == N){
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++)
                if((grid[i] >> (M-j-1))&1) cout << '*';
                else cout << ".";
            cout << endl;
        }
        exit(0);
    }

    for(int m : valr[rows[dep]]){
        grid[dep] = m;    

        bool go = true;
        for(int c=0; c<M; c++){
            int sf = 0;
            for(int i=0; i<=dep; i++)
                if((grid[i] >> (M-c-1))&1)
                    sf ^= (1 << i);
            go &= can_fin[dep][sf][cols[c]];
        }

        if(go) search(dep+1);
    }
}   

int main(){
    cin >> N >> M;

    rows.resize(N);
    for(int &x : rows) cin >> x;

    cols.resize(M);
    for(int &x : cols) cin >> x;

    for(int m=0; m<(1<<N); m++){
        valc[count_blocks(m)].push_back(m);
        for(int r=0; r<N; r++){
            int mm = (1<<(r+1)) - 1;
            can_fin[r][m&mm][count_blocks(m)] = true;
        }
    }

    for(int m=0; m<(1<<M); m++)
        valr[count_blocks(m)].push_back(m);

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    for(int i=0; i<20; i++)
        shuffle(valr[i].begin(), valr[i].end(), std::default_random_engine(seed));

    search(0);
}