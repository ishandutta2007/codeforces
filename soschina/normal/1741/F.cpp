#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>
#define lowbit(i) (i&-i)
using namespace std;
const int N = 4e5 + 1;

int t, n;
multiset<int> st;
int ans[N];

struct node{
    int id, l, r;
    node(int id, int l, int r) : id(id), l(l), r(r){}
};
vector<int> pos;
vector<node> vec[N];

long long tree[N], tree1[N];
void add(long long *tree, int i, long long val){
    while(i <= 2 * n){
        tree[i] += val;
        i += lowbit(i);
    }
}
long long getsum(long long *tree, int i){
    long long res = 0;
    while(i){
        res += tree[i];
        i -= lowbit(i);
    }
    return res;
}
void addseg(int l, int r, long long val){
    add(tree, l, val);
    add(tree, r + 1, -val);
    add(tree1, l, val * (l - 1));
    add(tree1, r + 1, -val * r);
}
long long sumseg(int l, int r){
    return (r * getsum(tree, r) - (l - 1) * getsum(tree, l - 1)) - (getsum(tree1, r) - getsum(tree1, l - 1));
}

int main(){
	scanf("%d", &t);
    while(t--){
        pos.clear();
        st.clear();
        scanf("%d", &n);
        memset(tree + 1, 0, sizeof(long long) * 2 * n);
        memset(tree1 + 1, 0, sizeof(long long) * 2 * n);
        for (int i = 1; i <= n; i++)
            vec[i].clear();
        for (int i = 1; i <= n; i++){
            int l, r, c;
            scanf("%d%d%d", &l, &r, &c);
            vec[c].push_back(node(i, l, r));
            pos.push_back(l), pos.push_back(r);
        }
        sort(pos.begin(), pos.end());
        int len = unique(pos.begin(), pos.end()) - pos.begin();
        while(pos.size() > len)
            pos.pop_back();
        for (int i = 1; i <= n; i++){
            for(node &nd : vec[i]){
                int l = lower_bound(pos.begin(), pos.end(), nd.l) - pos.begin() + 1;
                int r = lower_bound(pos.begin(), pos.end(), nd.r) - pos.begin() + 1;
                st.insert(nd.l), st.insert(nd.r);
                addseg(l, r, 1);
            }
        }
        for (int i = 1; i <= n; i++){
            for(node nd : vec[i]){
                st.erase(st.find(nd.l));
                st.erase(st.find(nd.r));
                int l = lower_bound(pos.begin(), pos.end(), nd.l) - pos.begin() + 1;
                int r = lower_bound(pos.begin(), pos.end(), nd.r) - pos.begin() + 1;
                addseg(l, r, -1);
            }
            for(node nd : vec[i]){
                int l = lower_bound(pos.begin(), pos.end(), nd.l) - pos.begin() + 1;
                int r = lower_bound(pos.begin(), pos.end(), nd.r) - pos.begin() + 1;
                if(sumseg(l, r) > 0){
                    ans[nd.id] = 0;
                    continue;
                }
                auto it = st.lower_bound(nd.r);
                ans[nd.id] = 0x7fffffff;
                if(it != st.end())
                    ans[nd.id] = min(ans[nd.id], *it - nd.r);
                if(it != st.begin()){
                    it--;
                    if(*it >= nd.l)
                        ans[nd.id] = 0;
                    else
                        ans[nd.id] = min(ans[nd.id], nd.l - *it);
                }
            }
            for(node nd : vec[i]){
                int l = lower_bound(pos.begin(), pos.end(), nd.l) - pos.begin() + 1;
                int r = lower_bound(pos.begin(), pos.end(), nd.r) - pos.begin() + 1;
                st.insert(nd.l), st.insert(nd.r);
                addseg(l, r, 1);
            }
        }
        for (int i = 1; i <= n; i++)
            printf("%d ", ans[i]);
        putchar('\n');
    }
	return 0;
}