// And you curse yourself for things you never done
 
#include<bits/stdc++.h>
 
#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
 
const int maxn = 2e4 + 10, mod = 1e9 + 7, inf = 1e9 + 10;

struct Flow{
    int cap[maxn];
    int mark[maxn], colo = 0, h[maxn], pp[maxn], to[maxn], tp[maxn], nxt[maxn], qu[maxn], C = 0;
    Flow(){
	memset(tp, -1, sizeof tp);
    }
    void add_edge(int a, int b, int c){
	nxt[C] = tp[a], cap[C] = c, to[C] = b, tp[a] = C;
	C++;
	nxt[C] = tp[b], cap[C] = 0, to[C] = a, tp[b] = C;
	C++;
    }
    bool bfs(int src, int snk){
	memset(h, -1, sizeof h);
	int L = 0, R = 1;
	qu[0] = src;
	h[src] = 0;
	while(L < R){
	    int u = qu[L++];
	    if(u == snk)
		return 1;
	    for(int id = tp[u]; id != -1; id = nxt[id]){
		if(h[ to[id] ] == -1 && cap[id] != 0)
		    h[ to[id] ] = 1 + h[u], qu[R++] = to[id];
	    }
	}
	return 0;
    }
    int dfs(int u, int snk, int f){
	if(u == snk)
	    return f;
	int ans = 0;
	while(pp[u] != -1){
	    int id = pp[u];
	    if(cap[id] != 0 && h[u]+1 == h[ to[id] ]){
		int num = dfs(to[id], snk, min(f - ans, cap[id]));
		
		ans+= num;
		cap[id]-= num, cap[id ^ 1]+= num;
		
		if(ans == f)
		    break;
	    }
	    pp[u] = nxt[ pp[u] ];
	}
	return ans;
    }    
    int flow(int src, int snk){
	int ans = 0;
	while(bfs(src, snk)){
	    memcpy(pp, tp, sizeof tp);
	    ans+= dfs(src, snk, inf);
	}
	return ans;
    }

    int FLW[maxn], pr[maxn];
    
    int bfs2(int src, int snk){
	int L = 0, R = 1;
	mark[src] = colo;
	qu[0] = src;
	FLW[src] = inf;	
	while(L < R && mark[snk] != colo){
	    int u = qu[L++];
	    for(int id = tp[u]; id != -1; id = nxt[id]){
		int y = to[id];
		if(mark[y] != colo && cap[id] != 0){
		    mark[y] = colo, FLW[y] = min(FLW[u], cap[id]), pr[y] = id, qu[R++] = y;
		    if(y == snk)
			break;
		}
	    }
	}
	if(mark[snk] != colo)
	    return 0;
	int ans = FLW[snk];
	while(snk != src){
	    int id = pr[snk];
	    cap[id]-= ans, cap[id^ 1]+= ans;
	    snk = to[id ^ 1];
	}
	return ans;
    }
    int flow2(int src, int snk){
 	int ans = 0;
	while(true){
	    colo++;
	    int num = bfs2(src, snk);	    
	    if(num == 0)
		break;
	    ans+= num;
	}
	return ans;
    }
};

const int maxk = 10, MAX = 25;

int ANS[(1<<maxk) + 10], n, k;
Flow flw;
int CAP[maxk][maxn];

void go(int pos, int msk, int F){
    if(pos == k){
	ANS[msk] = F;
	return;
    }
    memcpy(CAP[pos], flw.cap, sizeof CAP[pos]);
    go(pos+1, msk, F);    
    flw.cap[2 * pos] = MAX;
    go(pos+1, msk ^ (1<<pos), F + flw.flow2(0, n-1));
    memcpy(flw.cap, CAP[pos], sizeof CAP[pos]);
}
 
int arr[maxk], sm[1<<maxk];
 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    srand(time(0));

    vector<pair<pii, int> > vvv;
    
    int m, q;
    cin >> n >> m >> k >> q;
    for(int i = 0; i < m; i++){
	int a, b, c;
	cin >> a >> b >> c;
	--a, --b;
	vvv.PB({{a, b}, c});
	
	flw.add_edge(a, b, c);
    }

    random_shuffle(vvv.begin() + k, vvv.end());
    random_shuffle(vvv.begin(), vvv.begin() + k);
    
    go(0, 0, flw.flow(0, n-1));
    
    while(q--){
	for(int i = 0; i < k; i++){
	    cin >> arr[i];
	}
	int ans = inf;
	for(int msk = 0; msk < (1<<k); msk++){
	    if(msk == 0)
		sm[msk] = 0;
	    else
		sm[msk] = arr[ __builtin_ctz(msk) ] + sm[msk - (msk & -msk)];
	    ans = min(ans, sm[msk] + ANS[ ((1<<k) - 1) ^ msk ]);
	}
	cout << ans << "\n";
    }
    return 0;
}