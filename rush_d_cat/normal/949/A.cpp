#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
const int N = 2000000+10;
char s[N];
set<int> st[2];
vector<int> v[N]; int cnt;
bool vis[N];
int main() {
    scanf("%s", s);

    for(int i=0;s[i];i++) {
        if(s[i]=='0') st[0].insert(i);
        if(s[i]=='1') st[1].insert(i);
    }
    st[0].insert(N), st[1].insert(N);

    for(int i=0;s[i];i++) {
        if (vis[i]) continue;
        ++ cnt;

        if (s[i]=='1') {
            return !printf("-1\n");
        }
        int now = 0, cur = i;
        while (1) {
            st[now].erase(cur);
            v[cnt].push_back(cur+1); vis[cur]=1;

            int nex = *st[now^1].lower_bound(cur);

            now ^= 1, cur = nex; 
            //printf("%d %d\n", now, cur);
            if (nex == N) {
                //printf("%d\n", now);
                if (now==1) break;
                else return !printf("-1\n");
            }
        }
    }
    printf("%d\n", cnt);
    for(int i=1;i<=cnt;i++) {
        printf("%d ", v[i].size());
        for(int j=0;j<v[i].size();j++) {
            printf("%d ", v[i][j]);
        }
        printf("\n");
    }
}