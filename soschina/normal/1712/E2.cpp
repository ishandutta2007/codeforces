#include <cstdio>
#include <cstring>
#include <algorithm>
#define lowbit(i) (i&-i)
using namespace std;
const int N = 2e5 + 1;

int t;
struct node{
    int id, l, r;
    bool operator<(const node &b) const{
        return l < b.l;
    }
}qry[N];
long long ans[N];

int faccnt[N];

long long tree[N];
void add(int i, int x){
    while(i < N){
        tree[i] += x;
        i += lowbit(i);
    }
}

long long sum(int i){
    long long ret = 0;
    while(i){
        ret += tree[i];
        i -= lowbit(i);
    }
    return ret;
}

int main(){
    for (int i = 1; i < N; i++)
        for (int j = i + i; j < N; j += i){
            add(j, faccnt[j]);
            faccnt[j]++;

        }
    scanf("%d", &t);
    for (int i = 1; i <= t; i++){
        qry[i].id = i;
        scanf("%d%d", &qry[i].l, &qry[i].r);
        int n = qry[i].r - qry[i].l + 1;
        ans[i] = 1ll * n * (n - 1) * (n - 2) / 6;
        int ll = 2 * qry[i].l;
        if(ll <= qry[i].r)
            ans[i] -= qry[i].r / 6 - (ll - 1) / 6;
        ll = (qry[i].l * 5 - 1) / 2 + 1;
        if(ll <= qry[i].r)
            ans[i] -= (qry[i].r / 15 - (ll - 1) / 15);
    }
    sort(qry + 1, qry + 1 + t);
    int l = 1;
    for (int i = 1; i <= t; i++){
        while(l < qry[i].l){
            for (int j = l + l; j < N; j += l){
                faccnt[j]--;
                add(j, -faccnt[j]);
            }
            l++;
        }
        ans[qry[i].id] -= sum(qry[i].r);
    }
    memset(faccnt, 0, sizeof(faccnt));
    for (int i = 1; i <= t; i++)
        printf("%lld\n", ans[i]);
    return 0;
}