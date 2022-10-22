#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200005;
int n , m , K;
set< pair<int , int> > block;
vector< pair<int , int> > H[N] , V[N];
bool loop;
void addblock(int x , int y) {
    block.insert(make_pair(x , y));
    H[x + y].push_back(make_pair(x , y));
    V[x - y + m + 1].push_back(make_pair(x , y));            
}
LL res = 0;
struct opt {
    int x , y , d;
    bool operator != (const opt& R) {
        return x != R.x || y != R.y || d != R.d;
    }
};

opt getnext(opt cur) {
    int x = cur.x , y = cur.y , d = cur.d;
    if (d == 1 || d == 3) {
        vector< pair<int , int> >& v = V[x - y + m + 1];
        auto j = lower_bound(v.begin() , v.end() , make_pair(x , y));
        if (d == 1) {
            -- j;
            int X = j -> first , Y = j -> second;
            bool L = block.count(make_pair(X , Y + 1));
            bool R = block.count(make_pair(X + 1 , Y));
            res += abs(X - x);
            if (L && !R)
                return (opt) {X + 1 , Y , 2};
            else if (!L && R)
                return (opt) {X , Y + 1 , 0};
            else {
                loop = 1;
                return (opt) {X + 1 , Y + 1 , 3};
            }
        } else {
            int X = j -> first , Y = j -> second;
            bool L = block.count(make_pair(X , Y - 1));
            bool R = block.count(make_pair(X - 1 , Y)); 
            res += abs(X - x);
            if (L && !R)
                return (opt) {X - 1 , Y , 0};
            else if (!L && R)
                return (opt) {X , Y - 1 , 2};
            else {
                loop = 1;
                return (opt) {X - 1 , Y - 1 , 1};
            }
        }
    } else {
        vector< pair<int , int> >& v = H[x + y];
        auto j = lower_bound(v.begin() , v.end() , make_pair(x , y));
        if (d == 0) {
            -- j;
            int X = j -> first , Y = j -> second;
            bool L = block.count(make_pair(X , Y - 1));
            bool R = block.count(make_pair(X + 1 , Y)); 
            res += abs(X - x);
            if (L && !R)
                return (opt) {X + 1 , Y , 3};
            else if (!L && R)
                return (opt) {X , Y - 1 , 1};
            else {
                loop = 1;
                return (opt) {X + 1 , Y - 1 , 2};
            }
        } else {
            int X = j -> first , Y = j -> second;
            bool L = block.count(make_pair(X , Y - 1));
            bool R = block.count(make_pair(X + 1 , Y)); 
            res += abs(X - x);
            if (L && !R)
                return (opt) {X - 1 , Y , 1};
            else if (!L && R)
                return (opt) {X , Y + 1 , 3};
            else {
                loop = 1;
                return (opt) {X - 1 , Y + 1 , 0};
            }
        }
    }


}

void work() {
    int i , x , y , d;
    scanf("%d%d%d",&n,&m,&K);
    for (i = 0 ; i < K ; ++ i) {
        scanf("%d%d",&x,&y);
        addblock(x , y);
    }
    for (i = 1 ; i <= n ; ++ i) {
        addblock(i , 0);
        addblock(i , m + 1);       
    }
    for (i = 1 ; i <= m ; ++ i) {
        addblock(0 , i);
        addblock(n + 1 , i);       
    }
    addblock(0 , 0);
    addblock(n + 1 , 0);
    addblock(0 , m + 1);
    addblock(n + 1 , m + 1);
    for (i = 0 ; i <= n + m + 2 ; ++ i) {
        sort(H[i].begin() , H[i].end());
        sort(V[i].begin() , V[i].end());       
    }
    char dir[10];
    scanf("%d%d%s",&x,&y,dir);
    //"NE", "NW", "SW" or "SE"
    //These strings denote directions (-1,1), (-1,-1), (1,-1), (1,1).
    if (!strcmp(dir , "NE")) d = 0;
    if (!strcmp(dir , "NW")) d = 1;
    if (!strcmp(dir , "SW")) d = 2;
    if (!strcmp(dir , "SE")) d = 3;
    opt now = getnext((opt) {x , y , d}) , cur = now;
    //printf("%d %d %d\n" , now.x , now.y , now.d);
    //return;
    res = 0;
    do {
        opt nxt = getnext(cur);
        //printf("%d %d %d\n" , nxt.x , nxt.y , nxt.d);
        cur = nxt;
    } while (cur != now);
    if (loop)
        res >>= 1;
    cout << res << endl;
}

int main() {
    work();
    return 0;
}