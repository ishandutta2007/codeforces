#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

void setIO() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int SZ = 200005;
int n, m;
int a[SZ];
int p[SZ], sz[SZ], got[SZ];

int find(int u) {
    return u == p[u] ? u : (p[u] = find(p[u]));
}

void merge(int u, int v) {
    // cout<<"merging "<<u<<v<<endl;
    int ru = find(u);
    int rv = find(v);
    if (ru == rv)
        return;
    if (ru > rv)
        swap(ru, rv);
    p[ru] = rv;
    sz[rv] += sz[ru];
    // cout<<"merged sz =  "<<sz[rv]<<endl;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n;
        for (int i = 1; i <= n; i++) {
            int x; cin>>x;
            a[x] = i;
            p[i] = i;
            sz[i] = 1;
            got[i] = 0;
        }
        got[n+1]=0;
        for (int i = 1; i <= n; i++) {
            int pos = a[i];
            got[pos] = 1;
            if (got[pos-1]) merge(pos, pos-1);
            if (got[pos+1]) merge(pos, pos+1);
            // cout<<"pos = "<<pos<<", sz = "<<sz[find(pos)]<<endl;
            cout<<(sz[find(pos)] == i)?"1":"0";
        }
        cout<<"\n";
    }
    
    return 0;
}