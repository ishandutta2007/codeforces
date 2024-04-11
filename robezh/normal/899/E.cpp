#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<cstdlib>
using namespace std;

struct P {
    int first, second;

    P(int _first, int _second) {
        first = _first;
        second = _second;
    }

    bool operator < (P p) const {
        return first != p.first ? first < p.first : second > p.second;
    }
};

priority_queue<P> pque;

int nxt[200005], prv[200005], in[200005];
int st,ed;
int cap;

int n;
vector<P> V;
int tmp;

void del(int i);

void merge(int i, int j) {
    P pi = V[i];
    P pj = V[j];
    if(pi.first != pj.first) return ;
    V[i].second += V[j].second;
    pque.push(P(V[i].second, i));
    del(j);
}

void del(int i) {
    if(cap == 0) return ;

    cap--;
    in[i] = 0;
    if(cap == 0) return ;
    if(i == st) {
        st = nxt[i];
        prv[nxt[i]] = st;
    } else if(i == ed) {
        ed = prv[i];
        nxt[prv[i]] = ed;
    } else {
        nxt[prv[i]] = nxt[i];
        prv[nxt[i]] = prv[i];
        merge(prv[i],nxt[i]);
    }
}



int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        if(V.empty() || tmp != V[V.size()-1].first) V.push_back(P(tmp, 1));
        else V[V.size()-1].second++;
    }

    for(int i = 0; i < V.size(); i++) {
        if(i != 0) prv[i] = i-1;
        else st = prv[i] = 0;

        if(i != V.size()-1) nxt[i] = i+1;
        else ed = nxt[i] = V.size()-1;
    }
    for(int i = 0; i < V.size(); i++) {
        pque.push(P(V[i].second, i));
    }
    fill(in, in + V.size(), 1);
    cap = V.size();
    int cnt = 0;
    while(!pque.empty() && cap > 0) {
        P p = pque.top();
        pque.pop();
        if(!in[p.second] || p.first < V[p.second].second) continue;

        del(p.second);
        cnt ++;
    }

    cout << cnt;
}