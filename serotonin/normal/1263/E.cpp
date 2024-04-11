#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=1e6+5;

typedef pair <int,int> pii;

char s[sz], cmd[sz];
int ara[sz], extra[sz*3];
pii tree[sz*3];

void update(int node, int b, int e, int i, int j, int v)
{
    if(e<i || j<b) return;
    if(i<=b && e<=j) {
        tree[node].first += v;
        tree[node].second += v;
        extra[node] += v;
        return;
    }

    int l=node<<1;
    int r=(node<<1)+1;
    int m=(b+e)>>1;

    update(l, b, m, i, j, v);
    update(r, m+1, e, i, j, v);
    tree[node].first = max(tree[l].first, tree[r].first) + extra[node];
    tree[node].second = min(tree[l].second, tree[r].second) + extra[node];
}

pii query(int node, int b, int e, int i, int j, int carry)
{
    if(e<i || j<b) return make_pair(-sz, sz);
    if(i<=b && e<=j) {
        pii now = tree[node];
        now.first += carry;
        now.second += carry;
        return now;
    }

    carry+=extra[node];
    int l=node<<1;
    int r=(node<<1)+1;
    int m=(b+e)>>1;

    auto x = query(l, b, m, i, j, carry);
    auto y = query(r, m+1, e, i, j, carry);
    pii now;
    now.first = max(x.first, y.first);
    now.second = min(x.second, y.second);
    return now;
}

int main()
{
    int n, now=0;
    scanf("%d %s", &n, cmd);
    for(int i=0; i<n; i++) s[i]=' ';
    for(int i=0; i<n; i++) {
        char c = cmd[i];
        if(c=='R') now++;
        else if(c=='L') now=max(now-1, 0);
        else if('a'<=c && c<='z') {
            if(s[now]=='(') update(1, 0, n-1, now, n-1, -1);
            if(s[now]==')') update(1, 0, n-1, now, n-1, +1);
            s[now]=' ';
        }
        else if(s[now]!=c) {
            if(s[now]=='(') update(1, 0, n-1, now, n-1, -1);
            if(s[now]==')') update(1, 0, n-1, now, n-1, +1);
            if(c=='(') update(1, 0, n-1, now, n-1, +1);
            if(c==')') update(1, 0, n-1, now, n-1, -1);
            s[now]=c;
        }

        auto x = query(1, 0, n-1, 0, n-1, 0);
        auto y = query(1, 0, n-1, n-1, n-1, 0);

        if(x.second || y.second) printf("-1 ");
        else printf("%d ", x.first);
    }
}