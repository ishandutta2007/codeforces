#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=1e6+5;

int a[sz], spf[sz], dist[sz], par[sz], pcnt[sz], mp[sz];
vector <int> g[sz];

void prm()
{
    spf[1]=1;
    for(int i=2; i<sz; i++) {
        if(spf[i]) continue;
        for(int j=i; j<sz; j+=i) {
            if(!spf[j]) spf[j] = i;
        }
    }
}

int short_cyc(int s)
{
    int now = sz;
    queue <int> q;
    vector <int> here;
    dist[s] = 0, q.push(s), here.push_back(s);

    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int v : g[u]) {
            if(dist[v] == sz) {
                dist[v] = dist[u]+1;
                par[v] = u;
                q.push(v), here.push_back(v);
            }
            else if(par[u] != v && par[v] != u)
                now = min(now, dist[u] + dist[v] + 1);
        }
    }

    int root = 0;
    if(pcnt[s]) root = 2;
    else for(int v : g[s]) if(v>999 && pcnt[v]) root = 3, s = v;

    for(int v : here) {
        if(s-v && pcnt[v] && root) {
            now = min(now, dist[v] + root);
        }
        dist[v] = sz, par[v] = -1;
    }
    return now;
}

int main()
{
    prm();

    int n;
    cin >> n;
    for(int i=0; i<n; i++) scanf("%d", &a[i]), mp[a[i]]++;

    int ans = sz;
    for(int i=0; i<n; i++) {
        int x = spf[a[i]], bx = 0;
        while(x>1 && a[i]%x == 0) a[i]/=x, bx^=1;
        if(a[i]==1) {
            if(bx) pcnt[x]++;
            else ans = 1;
        }
        else {
            int y = spf[a[i]], by = 0;
            while(a[i]%y == 0) a[i]/=y, by^=1;
            if(bx && by) {
                g[x].push_back(y);
                g[y].push_back(x);
            }
            else if(bx) pcnt[x]++;
            else pcnt[y]++;
        }
    }

    if(ans == 1) {
        puts("1");
        return 0;
    }

    for(int i=0; i<sz; i++) {
        if(pcnt[i] > 1 || mp[i] > 1) {
            puts("2");
            return 0;
        }
    }

    for(int i=0; i<sz; i++) dist[i] = sz, par[i] = -1;
    for(int i=2; i<999; i++)
        ans = min(ans, short_cyc(i));

    if(ans == sz) ans = -1;
    printf("%d\n", ans);
}