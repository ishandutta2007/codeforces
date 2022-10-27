#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 30000000+2;
vector<int> v[100000+10];
int ch[N][2], val[N], size=0;

void insert(int x, int k) {
    int now=k;
    for(int i=19;i>=0;i--) {
        int bit = (x>>i)&1;
        if (ch[now][bit] == 0) {
            ch[now][bit] = ++size;
            //printf("%d %d %d\n", now, bit, size);
        }
        now = ch[now][bit];

        val[now] = min(val[now], x);
        //printf("now = %d, bit = %d, val = %d\n", now, bit, val[now]);
    }
    //printf("\n");
}
int query(int x, int k, int mx) {
    int now=k;
    for(int i=19;i>=0;i--) {
        int bit=(x>>i)&1;
        //printf("%d %d, cur = %d, mn = %d\n", now,bit,ch[now][bit], val[ch[now][bit]]);
        if (ch[now][bit^1] && val[ch[now][bit^1]] <= mx) {
            now = ch[now][bit^1];
        } else if (ch[now][bit] && val[ch[now][bit]] <= mx) {
            now = ch[now][bit];
        } else {
            return -1;
        }
    }
    return val[now];
}
int q;
void init() {
    size=100000;
    for(int i=1;i<=100000;i++)
        for(int j=i;j<=100000;j+=i)
            v[j].push_back(i);
    for(int i=1;i<N;i++) val[i]=N;
}
int main() {
    init();
    scanf("%d",&q);
    while(q --) {
        int op, x, k, s;
        scanf("%d",&op);
        if (op == 1) {
            scanf("%d", &x);
            for(int i=0;i<v[x].size();i++) {
                insert(x, v[x][i]);
            }
        } else {
            scanf("%d%d%d",&x,&k,&s);
            if (x%k) {
                printf("-1\n");
                continue;
            }
            printf("%d\n",query(x,k,s-x));
        }
    } 
}