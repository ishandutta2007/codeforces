#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

const int MAXU = 300005;
const int MAXN = 100005;

struct triple{
    int v[3];
    bool operator <(const triple &y) const{ return v[0] > y.v[0]; }
};

pair<int, int> sv[3][MAXN];
int N, M, av[MAXU];
triple fo[MAXU];

map<int, int> pf;
map<int, int> cd;

void erase(int v){ if(cd[v]>1) cd[v]--; else cd.erase(v); }
void insert(int v){ cd[v]++; }

void del(map<int, int>::iterator it){
    erase(prev(it)->first + it->second);
    erase(it->first + next(it)->second);
    insert(prev(it)->first + next(it)->second);
    pf.erase(it);
}

void add(int x, int y){
    auto it = pf.lower_bound(x);
    erase(prev(it)->first + it->second);
    insert(prev(it)->first + y);
    insert(x + it->second);
    pf[x] = y;
}

void ins(triple &t){
    auto it = pf.lower_bound(t.v[1]);
    if(it->second < t.v[2]){
        if(it->first == t.v[1]){ del(it); }
        add(t.v[1], t.v[2]); 
        for(it = --pf.lower_bound(t.v[1]); it->second < t.v[2];)
            del(it--);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N;
    for(int i=0; i<3; i++){
        for(int j=0; j<N; j++){
            cin >> sv[i][j].first;
            sv[i][j].second = j;
            av[M++] = sv[i][j].first;
        }
        sort(sv[i], sv[i]+N);
    }

    sort(av, av+M);
    M = unique(av, av+M) - av;

    for(int i=0; i<M; i++){
        for(int j=0; j<3; j++){
            auto it = lower_bound(sv[j], sv[j]+N, make_pair(av[i], -1));
            if(it==(sv[j]+N) || it->first != av[i]) fo[i].v[j] = MAXU;
            else fo[i].v[j] = it->second + 1;
        }
    }
    sort(fo, fo+M);

    pf[0] = MAXU;
    pf[MAXU+1] = 0;
    cd[0] = 1;

    int ans = MAXU;
    for(int i=0; i<M; i++){
        ans = min(ans, fo[i].v[0] + cd.begin()->first);
        ins(fo[i]);
    }
    cout << min(ans, cd.begin()->first) << endl;
    return 0;
}