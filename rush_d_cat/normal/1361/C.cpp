#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 20;
namespace FindEulerPath {
    int n,m,deg[N],par[N];
    int head[N<<1],eCnt;
    int find(int x) {
        return par[x]==x?x:par[x]=find(par[x]);
    }
    struct Edge {
        int u,v,nex,fg,id;
    } edge[N<<1];
    void addEdge(int u,int v){
    	par[find(u)]=find(v);
    	deg[u]++;
        edge[eCnt].u=u, edge[eCnt].v=v, edge[eCnt].nex=head[u], edge[eCnt].fg=0;
        head[u]=eCnt++;
    }
    int vStk[N],vTop;
    int eStk[N],eTop;
    vector<int> vPath, ePath;
    void init(int n_, int m_) {
        eCnt=vTop=eTop=0; n = n_, m = m_;
        vPath.clear(); ePath.clear();
        for(int i=0;i<=n;i++) par[i]=i,deg[i]=0,head[i]=-1;
    }
	bool chkvalid(int src){
		for(int i=0;i<=n;i++) if(deg[i]%2) return false;
		for(int i=0;i<=n;i++) if(deg[i] && find(i)!=find(src)) return false;
		return true;
	}
    void eulerpath(int src){
        vPath.clear(); vStk[vTop=1]=src;
        ePath.clear(); eTop = 0;
        while(vTop){
            int u=vStk[vTop];
            if(head[u]==-1){
                {
                    vPath.push_back(u); --vTop;
                }
                if(eTop) {
                    ePath.push_back(eStk[eTop]); --eTop;
                }
                continue;
            }
            int v=edge[head[u]].v;
            if(edge[head[u]].fg) {
                head[u]=edge[head[u]].nex; continue;
            }
            edge[head[u]].fg = edge[head[u]^1].fg = 1;
            vStk[++vTop] = edge[head[u]].v; 
            eStk[++eTop] = head[u];
        }
    }
}
int nn;
int a[N], b[N], f[N], C;

bool chk(int x) {
	int val = (1 << x) - 1;
	//printf("x = %d, val = %d\n", x, val);
	FindEulerPath::init(val, nn);
	for (int i = 1; i <= nn; i ++) {
		FindEulerPath::addEdge(a[i] & val, b[i] & val);
		FindEulerPath::addEdge(b[i] & val, a[i] & val);
		//printf("link %d %d\n", a[i] & val, b[i] & val);
	}
	if (FindEulerPath::chkvalid(a[1] & val) == false) return 0;
	printf("%d\n", x);
	FindEulerPath::eulerpath(a[1] & val);
	vector<int> vec;
	reverse(FindEulerPath::ePath.begin(), FindEulerPath::ePath.end());
	for (int i = 0; i < FindEulerPath::ePath.size(); i ++) {
		int id = FindEulerPath::ePath[i];
		// printf("%d ", id);
		
		if (id % 2 == 0) {
			printf("%d %d ", id + 1, id + 2);
			//int A = a[id] ^ b[id + 1];
			//assert(A % (1<<x) == 0);
			//vec.push_back(f[id+1]); vec.push_back(f[id+2]);
		}
		else {
			printf("%d %d ", id + 1, id);
			//vec.push_back(f[id+1]); vec.push_back(f[id]);
			//int A = a[id] ^ b[id - 1];
			//assert(A % (1<<x) == 0);
		}
		
	} 
	printf("\n");
	/*
	for (int i = 1; i + 1 < vec.size(); i += 2) printf("# %d\n", vec[i] ^ vec[i+1]);
	for (int i = 0; i < FindEulerPath::vPath.size(); i ++) {
		printf("%d ", FindEulerPath::vPath[i]);
	} 
	printf("\n");
	*/
	exit(0);
}

int main() {
	scanf("%d", &nn);
	for (int i = 1; i <= nn; i ++) {
		scanf("%d%d", &a[i], &b[i]); f[++C] = a[i], f[++C] = b[i];
	}
	// chk(2); return 0;
	for (int i = 20; i >= 0; i --) chk(i);
}