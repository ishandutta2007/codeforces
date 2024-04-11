#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 50005;
const int MAXQ = 500005;
const int MAXF = 1005;

int N, O, M, Q, T;

int nf[MAXN];
bool fat[MAXN];
int map[MAXN];
vector<int> fatty;

bool onl[MAXN];
int fon[MAXN];
vector<int> know[MAXN];
bool fatf[MAXF][MAXF];

struct query{ char t; int u, v; } que[MAXQ];

void dec(int qi){ que[qi].u--; que[qi].v--; }
void rec(int qi){ nf[que[qi].u]++; nf[que[qi].v]++; }

vector<int>::iterator binary_search(int i, int j){
    return lower_bound(know[i].begin(), know[i].end(), j);
}

bool is_friend(int i, int j){
    if(fat[i]){
        if(fat[j]) return fatf[map[i]][map[j]];
        return is_friend(j, i);
    }
    auto it = binary_search(i, j);
    if(it == know[i].end()) return false;
    return *it == j;
}

void mark_friend(int i, int j){
    if(fat[i]){
        if(fat[j]) fatf[map[i]][map[j]] = true;
    }
    else{
        auto it = binary_search(i, j);
        know[i].insert(it, j);
    }
}

void unmark_friend(int i, int j){
    if(fat[i]){
        if(fat[j]) fatf[map[i]][map[j]] = false;
    }
    else know[i].erase(binary_search(i, j));
}

void online(int i){
    for(int f : fatty)
        if(is_friend(f, i)) fon[f]++;
    onl[i] = true;
}

void offline(int i){
    for(int f : fatty)
        if(is_friend(f, i)) fon[f]--;
    onl[i] = false;
}

void add_friend(int u, int v){
    if(fat[u]) fon[u] += onl[v];
    if(fat[v]) fon[v] += onl[u];
    mark_friend(u, v);
    mark_friend(v, u);    
}

void del_friend(int u, int v){
    if(fat[u]) fon[u] -= onl[v];
    if(fat[v]) fon[v] -= onl[u];
    unmark_friend(u, v);
    unmark_friend(v, u);
}

int count_online(int i){
    if(fat[i]) return fon[i];
    else{ int ret = 0; for(int f : know[i]) ret += onl[f]; return ret; }
}

int main(){
    scanf("%d %d %d\n%d", &N, &M, &Q, &O);
    for(int i=0; i<O; i++){
        scanf("%d", &(que[T].u));
        dec(T);
        que[T++].t = 'O';
    }

    for(int i=0; i<M; i++){
        scanf("%d %d", &(que[T].u), &(que[T].v));
        dec(T);
        rec(T);
        que[T++].t = 'A';
    }

    for(int i=0; i<Q; i++){
        scanf(" %c %d", &(que[T].t), &(que[T].u));
        if(que[T].t == 'A' || que[T].t == 'D') scanf("%d", &(que[T].v));
        dec(T);
        if(que[T].t == 'A') rec(T);
        T++;
    }

    for(int i=0; i<N; i++)
        if(nf[i] >= 400){
            fat[i] = true;
            map[i] = fatty.size();
            fatty.push_back(i);
        }

    for(int i=0; i<T; i++){
        int u = que[i].u, v = que[i].v;
        switch(que[i].t){
            case 'O': online(u); break;
            case 'F': offline(u); break;
            case 'A': add_friend(u, v); break;
            case 'D': del_friend(u, v); break;
            case 'C': printf("%d\n", count_online(u));
        }
    }

    return 0;
}