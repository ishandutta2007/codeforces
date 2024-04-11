#include <iostream>
#include <map>
using namespace std;

int N, M, MOD;
char grid[512][512];
int onec[512];

map<pair<int, int>, int> cache[512];

int hmult(int a, int b, int c){
    return ((long long)c * ((a * b / 2) % MOD)) % MOD;
}

int ways(int rows, int twos, int ones){
    pair<int, int> key = make_pair(twos, ones);
    if(cache[rows].count(key)) return cache[rows][key];

    if(rows == 0)
        return cache[rows][key] = (key.first==0) && (key.second==0);

    int ans = 0;
    if(twos >= 2)
        ans = (ans + hmult(twos, (twos-1), ways(rows-1, twos-2, ones+2))) % MOD;
    if(twos >= 1 && ones >= 1)
        ans = (ans + hmult(2*twos, ones, ways(rows-1, twos-1, ones))) % MOD;
    if(ones >= 2)
        ans = (ans + hmult(ones, (ones-1), ways(rows-1, twos, ones-2))) % MOD;

    return cache[rows][key] = ans;
}

int main(){
    cin >> N >> M >> MOD;

    for(int i=0; i<M; i++)
        for(int j=0; j<N; j++){
            cin >> grid[i][j];
            onec[j] += (grid[i][j]=='1');
        }

    int twos = 0, ones = 0;
    for(int i=0; i<N; i++)
        if(onec[i] == 0) twos++;
        else if(onec[i] == 1) ones++;

    cout << ways(N-M, twos, ones) << endl;
    return 0;
}