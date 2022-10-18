#include <string.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

struct pack{
    int in, out;
    int weight;
    int strength;
    int value;
};

bool operator<(const pack &x, const pack &y){
    if(x.in == y.in) return x.out > y.out;
    return x.in < y.in;
}

int N, S;
pack boxes[505];

int pay[505][1005];
bool seen[505][1005];

int calc(int i, int s);

int do_dp(int *suff, bool *done, int wsuff, int help, int right_end, int strong){
    if(wsuff >= right_end) return 0;
    if(done[wsuff]) return suff[wsuff];
    done[wsuff] = true;

    while(help <= N && (boxes[help].in < wsuff || boxes[help].out > right_end)) help++;
    if(help > N) return suff[wsuff] = 0;

    suff[wsuff] = 0;

    while(help <= N && boxes[help].in == wsuff){
        int new_strong = min(strong - boxes[help].weight, boxes[help].strength);
        if(boxes[help].in == wsuff && new_strong >= 0){
            int repo = calc(help, new_strong);
            repo += boxes[help].value;
            suff[wsuff] = max(suff[wsuff], repo + do_dp(suff, done, boxes[help].out, help, right_end, strong));  
        }
        help++;
    }

    suff[wsuff] = max(suff[wsuff], do_dp(suff, done, wsuff+1, help, right_end, strong));
    return suff[wsuff];
}


int calc(int i, int s){

    if(i >= N) return 0;
    
    if(seen[i][s]) return pay[i][s];
    seen[i][s] = true;

    int *suff = (int *) malloc(sizeof(int) * 1010);
    bool *done = (bool *) malloc(sizeof(bool) * 1010);
    memset(done, 0, sizeof(bool) * 1010);    

    pay[i][s] = do_dp(suff, done, boxes[i].in, i+1, boxes[i].out, s);

    free(suff);
    free(done);
    return pay[i][s];
}

unordered_set<int> uniq;
vector<int> vals;
unordered_map<int, int> comp;

void compress(){
    for(int i=0; i<=N; i++){
        if(!uniq.count(boxes[i].in)){
            vals.push_back(boxes[i].in);
            uniq.insert(boxes[i].in);
        }
        if(!uniq.count(boxes[i].out)){
            vals.push_back(boxes[i].out);
            uniq.insert(boxes[i].out);
        }
    }

    sort(vals.begin(), vals.end());

    for(int i=0; i<vals.size(); i++)
        comp[vals[i]] = i;

    for(int i=0; i<=N; i++){
        boxes[i].in = comp[boxes[i].in];
        boxes[i].out = comp[boxes[i].out];
    }
}

int main(){
    cin >> N >> S;

    for(int i=0; i<N; i++){
        cin >> boxes[i].in >> boxes[i].out;
        cin >> boxes[i].weight;
        cin >> boxes[i].strength;
        cin >> boxes[i].value;
    }

    boxes[N].in = -1;
    boxes[N].out = 1 << 25;

    compress();
    sort(boxes, boxes + N + 1);

    cout << calc(0, S) << endl;
    return 0;
}