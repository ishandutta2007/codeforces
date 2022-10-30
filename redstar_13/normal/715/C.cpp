#include <bits/stdc++.h>

using namespace std;
typedef long long INT;
typedef double DO;
typedef pair<int, int> pii;
typedef vector<int> VI;

int n, M;

int power(int a, int b, int ans=1) {
    for (; b; b>>=1, a=(INT)a*a%M) if (b&1) ans=(INT)ans*a%M;
    return ans;
}

void smax(int &x, const int &y) {if (x>y) x=y;}
#define NN 101010

int fa[NN], vst[NN], sz[NN];
int qf, qb, q[NN], p[NN], rev[NN];
VI adj[NN], wei[NN];

INT ans;

int find_root(int u){
	qf=qb=0;
	q[qb++]=u; fa[u]=0;
	while(qf<qb){
		u=q[qf++];
		for(int i=adj[u].size(); i--; ){
			int v=adj[u][i];
			if(v==fa[u] || vst[v]) continue;
			fa[v]=u;
			q[qb++]=v;
		}
	}
	int nn=qb;
	for(int i=nn; i--; ){
		sz[u=q[i]]=1;
		int mx=0;
		for(int j=adj[u].size(); j--; ){
			int v=adj[u][j];
			if(v==fa[u] || vst[v]) continue;
			smax(mx, sz[v]);
			sz[u]+=sz[v];
		}
		if(mx*2<=nn && sz[u]*2>=nn) return u;
	}
}

int vis[NN], flag, dep[NN], val[NN], val1[NN];
VI tmp[NN];

const int MM = (1<<20)-1;
int head[MM+1], nxt[MM+1], E, key[MM+1], data[MM+1];

void add(int u) {
    int t=u&MM;
    for (int e=head[t]; e; e=nxt[e]) {
        if (key[e]==u) {
            data[e]++;
            return ;
        }
    }
    key[++E]=u; data[E]=1; nxt[E]=head[t]; head[t]=E;
}

int get_ans(int u) {
    int t=u&MM;
    for (int e=head[t]; e; e=nxt[e]) if (key[e]==u) return data[e];
    return 0;
}

void clear() {
    for (int i=1; i<=E; i++) head[key[i]&MM]=0;
    E=0;
}

void calc(int u, int pa=0) {
    for (int i=0; i<adj[u].size(); i++) {
        int v=adj[u][i];
        if (vst[v]) continue;
        ++flag;
        vis[u]=vis[v]=flag;
        qf=qb=0;
        q[qb++]=v; val[v]=val1[v]=wei[u][i]%M; dep[v]=1;
        while (qf<qb) {
            int uu=q[qf++];
            for (int j=0, vv; j<adj[uu].size(); j++) if (!vst[vv=adj[uu][j]] && vis[vv]!=flag) {
                vis[vv]=flag;
                q[qb++]=vv;
                dep[vv]=dep[uu]+1;
                val[vv]=((INT)val[uu]*10+wei[uu][j])%M;
                val1[vv]=(val1[uu]+(INT)wei[uu][j]*p[dep[uu]])%M;
            }
        }
        tmp[v].resize(qb);
        for (int j=0; j<qb; j++) tmp[v][j]=q[j];
    }

    for (int i=0; i<2; i++) {
        for (int v : adj[u]) if (!vst[v]) {
            for (int t : tmp[v]) {
                ans += get_ans((INT)rev[dep[t]]*(M-val[t])%M);
            }
            for (int t : tmp[v]) add(val1[t]);
        }
        clear();
        reverse(adj[u].begin(), adj[u].end());
    }

    for (int v : adj[u]) if (!vst[v]) for (int t : tmp[v]) ans+=(val[t]==0)+(val1[t]==0);

    for (int v : adj[u]) if (!vst[v]) tmp[v].clear();
}

void solve(int u) {
    u=find_root(u);
    calc(u);
    vst[u]=1;
    for (int v : adj[u]) {
        if (!vst[v]) solve(v);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif

    cin>>n>>M;
    int u, v, c;
    for (int i=1; i<n; i++) {
        scanf("%d%d%d", &u, &v, &c);
        u++; v++;
        adj[u].push_back(v); wei[u].push_back(c);
        adj[v].push_back(u); wei[v].push_back(c);
    }

    if (M==1) {
        cout << (INT)n*(n-1) << endl;
        return 0;
    }

    int t=M, phi=M;
    for (int i=2; i*i<=t; i++) if (t%i==0) {
        while (t%i==0) t/=i;
        phi-=phi/i;
    }
    if (t>1) phi-=phi/t;
    rev[1]=power(10, phi-1);
    for (int i=2; i<=n; i++) rev[i]=(INT)rev[i-1]*rev[1]%M;
    for (int i=p[0]=rev[0]=1; i<=n; i++) p[i]=(INT)p[i-1]*10%M;

    solve(1);

    cout << ans << endl;

    return 0;
}