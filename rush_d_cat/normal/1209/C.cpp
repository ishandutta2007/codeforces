#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;

int T,n,vis[N];
char s[N];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%s",&n,s+1);
        bool fg = 0;
        for(int d='0';d<='9';d++){
            vector<int> v,v1;
            int laspos = 0;
            for(int i=1;i<=n;i++) {
                vis[i]=0;
                if(s[i]<d) laspos = i;
            }
            for(int i=1;i<=n;i++) {
                if(s[i]<d) {
                    v.push_back(s[i]); vis[i]=1;
                } else if(s[i]==d) {
                    if (i > laspos) {v.push_back(s[i]); vis[i]=1;}
                } 
            }
            for(int i=1;i<=n;i++) {
                if(!vis[i]) v.push_back(s[i]);
            }

            bool ok=1;
            for(int i=1;i<v.size();i++) {
                //printf("# %c\n", v[i]);
                if(v[i]<v[i-1]) ok=0;
            }
            if(ok) {
                fg = 1;
                break;
            }
        }

        if(fg==0) printf("-\n");
        else {
            for(int i=1;i<=n;i++) printf("%d", vis[i]==1 ? 1 : 2);
            printf("\n");
        }
    }
}