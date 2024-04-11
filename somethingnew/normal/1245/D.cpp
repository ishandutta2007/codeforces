#include <iostream>
#include <vector>
#include "algorithm"


using namespace std;
struct heap{
    vector<long long> heap;
    long long size = 0;
    long long pos = 0;
    vector<long long> names;
    vector<long long> positions;
    void reserve(long long x){
        heap.assign(x, 1000000000000000000);
        names.assign(x, -1);
        return;
    }
    void reservenames(long long x){
        positions.assign(x + 1, -1);
        return;
    }
    void addtoheap2(long long x, long long name){
        pos = size;
        size++;
        heap[pos] = x;
        names[pos] = name;
        positions[name] = pos;
        while (pos != 0 and heap[pos] < heap[(pos-1) / 2]){
            swap(positions[names[pos]], positions[names[(pos-1)/2]]);
            swap(heap[pos],heap[(pos-1)/2]);
            swap(names[pos], names[(pos-1)/2]);
            pos -= 1;
            pos /= 2;
        }
        return;
    }
    void addtoheap1(long long pos, long long x){
        if (x>= heap[pos]) return;
        heap[pos] = x;
        while (pos != 0 and heap[pos] < heap[(pos-1) / 2]){
            swap(positions[names[pos]], positions[names[(pos-1)/2]]);
            swap(heap[pos],heap[(pos-1)/2]);
            swap(names[pos], names[(pos-1)/2]);
            pos -= 1;
            pos /= 2;
        }
        return;
    }
    void addtoheap(long long x, long long name){
        if (positions[name] == -2) return;
        if (positions[name] != -1){
            addtoheap1(positions[name], x);
        }else{
            addtoheap2(x, name);
        }
    }
    vector<long long> getmax(){
        return {heap[0], names[0]};
    }
    void removemax(){
        pos = 0;
        heap[pos] = 1000000000000000000;
        positions[names[pos]] = -2;
        names[pos] = -1;
        size--;
        swap(heap[pos],heap[size]);
        swap(names[pos], names[size]);
        positions[names[pos]] = 0;
        while (pos*2 + 1 <= size and heap[pos] > min(heap[pos*2+1],heap[pos*2+2])){
            if (heap[pos*2+1] < heap[pos*2+2]){
                swap(positions[names[pos]], positions[names[pos*2+1]]);
                swap(heap[pos],heap[pos*2+1]);
                swap(names[pos],names[pos*2+1]);
                pos = pos*2 + 1;
            } else{
                swap(positions[names[pos]], positions[names[pos*2+2]]);
                swap(heap[pos],heap[pos*2+2]);
                swap(names[pos],names[pos*2+2]);
                pos = pos*2 + 2;
            }
        }
        return;
    }
};
int main() {
    long long n;
    cin >> n;
    vector<long long> hh(n + 1);
    vector<vector<long long>> graph;
    graph.assign(n + 1, hh);
    vector<pair<long long,long long>> coord(n,{0,0});
    for (long long i = 0; i < n; ++i) {
        cin >> coord[i].first >> coord[i].second;
    }
    vector<long long> c(n,0);
    vector<long long> k(n,0);
    for (long long l = 0; l < n; ++l) {
        cin >> c[l];
    }
    for (long long l = 0; l < n; ++l) {
        cin >> k[l];
    }
    for (long long i = 0; i < n; ++i) {
        for (long long j = 0; j < n; ++j) {
            graph[i][j] = (k[i] + k[j]) * (abs(coord[i].first - coord[j].first) + abs(coord[i].second - coord[j].second));
        }
    }
    for (long long i = 0; i < n; ++i) {
        graph[n][i] = c[i];
        graph[i][n] = c[i];
    }
    heap hp;
    hp.reserve(n+2);
    hp.reservenames(n+2);
    vector<pair<long long, long long>> edges;
    vector<long long> electro;
    long long money = 0;
    vector<pair<long long, long long>> parent(n, {(long long)-1,(long long)-1});
    vector<long long> stop = {-1,-1};
    hp.addtoheap(0,n);
    hp.removemax();
    for (long long i = 0; i < n; ++i) {
        hp.addtoheap(graph[n][i], i);
    }
    vector<long long> now = hp.getmax();
    while(now[1] != -1){
        hp.removemax();
        money += now[0];
        if(now[0] == c[now[1]]){
            electro.push_back(now[1] + 1);
        }else{
            edges.push_back({parent[now[1]].first + 1, now[1] + 1});
        }
        for (long long i = 0; i < n; ++i) {
            hp.addtoheap(graph[now[1]][i], i);
            if(parent[i].first == -1 or parent[i].second > graph[now[1]][i]){
                parent[i].first = now[1];
                parent[i].second = graph[now[1]][i];
            }
        }
        now = hp.getmax();
    }
    cout << money << endl;
    cout << electro.size() << endl;
    for (auto i : electro) cout << i << ' ';
    cout << endl;
    cout << edges.size() << endl;
    for (auto i : edges) {
        cout << i.first << ' ' << i.second << endl;
    }
}