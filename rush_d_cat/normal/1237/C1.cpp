#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <vector>
#include <map>
using namespace std;
const int N = 200000 + 10;

int n, x[N], y[N], z[N];
map< pair<int,int>, set<int> > st3;
map< int, set< pair<int,int> > > st2;
multiset<int> st1;
map< pair<pair<int,int>,int>, int > mp;

struct P {
    int x,y,z, id;
    bool operator<(const P&o) const{
        return x < o.x;
    } 
} p[N], pp[N];

int ban[N];
void del(int id) {
    ban[id] = 1;
    st1.erase(st1.find(p[id].x));
    st2[p[id].x].erase( make_pair(p[id].y, p[id].z) );
    st3[make_pair(p[id].x, p[id].y)].erase(p[id].z);
}

void match(int id) {
   // printf("id = %d\n", );
    //printf("%d\n", id);
    del(id);
    //printf("ok %d\n", p[id].x);
    int x = *st1.lower_bound(p[id].x);
    //printf("x = %d\n", x);
    auto it = st2[x].lower_bound( make_pair(p[id].y, -1e9) );
    if (it == st2[x].end()) it --;
    int y = (*it).first;
    //printf("y = %d\n", y);
    auto it2 = st3[make_pair(x, y)].lower_bound(p[id].z);
    if (it2 == st3[make_pair(x, y)].end()) it2 --;
    int z = *it2;
    //printf("z = %d\n", z);
    int id2 = mp[make_pair(make_pair(x,y),z)];
    del(id2);
    printf("%d %d\n", id, id2);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].z); p[i].id = i;
        mp[make_pair(make_pair(p[i].x, p[i].y), p[i].z)] = i;
        st1.insert(p[i].x);
        st2[p[i].x].insert(make_pair(p[i].y, p[i].z));
        st3[make_pair(p[i].x, p[i].y)].insert(p[i].z);
        pp[i] = p[i];
    }
    sort(pp+1, pp+1+n);
    for (int i = 1; i <= n; i ++) {
        if (ban[pp[i].id]) continue;
        match(pp[i].id);
    }
}