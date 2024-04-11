#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 2e5 + 1, p = 998244353;

int t, n, s, a[N], b[N];
bool useda[N], usedb[N];

struct node{
    int p;
    bool type;
    node(int p, bool type) : p(p), type(type){}
    bool operator<(const node &b) const{
        return p != b.p ? p < b.p : type < b.type;
    }
};

vector<node> vec;

int main(){
    scanf("%d", &t);
    while(t--){
        memset(useda + 1, 0, sizeof(bool) * n);
        memset(usedb + 1, 0, sizeof(bool) * n);
        vec.clear();
        scanf("%d%d", &n, &s);
        for (int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
        }
        bool flag = true;
        for (int i = 1; i <= n; i++){
            scanf("%d", &b[i]);
            if(b[i] != -1){
                useda[a[i]] = true;
                usedb[b[i]] = true;
                if(a[i] > b[i] + s)
                    flag = false;
            }
        }
        if(!flag){
            puts("0");
            continue;
        }
        for (int i = 1; i <= n; i++){
            if(!useda[i]){
                vec.push_back(node(i, 0));
            }
            if(!usedb[i]){
                vec.push_back(node(i + s, 1));
            }
        }
        sort(vec.begin(), vec.end());
        int ans = 1, cnt = 0;
        for(node nd : vec){
            if(nd.type == 0)
                cnt++;
            else{
                ans = 1ll * ans * cnt % p;
                cnt--;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}