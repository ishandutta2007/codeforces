#include <iostream>
#include <cmath>
#include <set>
#include <vector>
using namespace std;
typedef long long LL;
int n, k;
pair<int,int> ask(set<int> v) {
    int c=0;
    printf("? ");
    for(auto x: v) {
        printf("%d", x); c++;
        if (c==k){
            printf("\n");
        } else {
            printf(" ");
        }
    }
    fflush(stdout);
    pair<int,int> ans;
    scanf("%d%d",&ans.first,&ans.second);
    return ans;
}
const int N=502;
bool vis[N];
int main() {
    scanf("%d%d",&n,&k); 
    set<int> s;
    for(int i=1;i<=k;i++){
        s.insert(i);
    }
    pair<int,int> p1 = ask(s);
    s.erase(p1.first);
    s.insert(k+1);
    pair<int,int> p2 = ask(s);
    bool fg = (p2.second < p1.second ? 1 : 0);
    s.insert(p1.first);
    int m = 1;
    for (int i = 1; i <= k; i ++){
        if (i == p1.first) continue;
        s.erase(i);
        pair<int,int> p3 = ask(s);
        if (fg == 1) {
            if (p3.second == p1.second) {
                m ++;
            }
        } else {
            if (p3.second != p1.second) {
                m ++;
            }
        }
        s.insert(i);
    }
    printf("! %d\n", m);
    fflush(stdout);
}

/*
[.$.. # ...] .
*/