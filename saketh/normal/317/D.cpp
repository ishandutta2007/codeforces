#include <iostream>
#include <set>
using namespace std;

int N;
set<int> imp;

int vals[25] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
                    16, 18, 20, 21, 22, 24, 25, 26, 27, 28, 30};
int nim[1 << 25];
bool visit[1 << 25];

int calc(int mask){
    if(visit[mask]) return nim[mask];
    visit[mask] = true;
    if(mask == 0) return nim[mask] = 1;

    bool seen[40];
    for(int i=0; i<40; i++)
        seen[i] = false;
    seen[0] = true;

    for(int i=0; i<25; i++){
        if(mask & (1<<i)){
            int new_mask = mask;
            for(int j=i; j<25; j++)
                if(!(vals[j] % vals[i]))
                    new_mask &= ~(1 << j);
                seen[calc(new_mask)] = true;
        }
    }

    int low = 40;
    for(int i=0; i<40; i++)
        if(!seen[i]){
            low = i;
            break;
        }

    return nim[mask] = low;
}

int nimber(int game_size){
    int mask = 0;
    for(int i=0; i<25; i++)
        if(vals[i] <= game_size)
            mask |= 1<<i;

    int mg = game_size - 1 - __builtin_popcount(mask);
    return 1 + ((calc(mask)-1)^(mg%2));
}

int main(){
    cin >> N;

    int res = 0;
    for(int i = 2; i*i <= N; i++){
        if(imp.count(i)) continue;
        int gs = 0;
        for(long long p = i; p <= N; p *= i){
            gs++;
            imp.insert((int)p);
        }
        res ^= nimber(gs);
    }

    res ^= (N - imp.size())%2;
    cout << ((res)?"Vasya":"Petya") << endl;
    return 0;
}