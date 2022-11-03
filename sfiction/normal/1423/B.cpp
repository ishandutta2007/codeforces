#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN=22000,MAXM=240000;
struct Dinic{
	struct edge{
		int x,y; 
		int c; 
		int f; 
		edge *next,*back; 
		edge(int x,int y,int c,edge* next):x(x),y(y),c(c),f(0),next(next),back(0){}
		void* operator new(size_t, void *p){return p;}
	}*E[MAXN],*data;
	char storage[2*MAXM*sizeof(edge)];
	int S,T;
	
	int Q[MAXN];
	int D[MAXN];
	void DFS(){
		memset(D,-1,sizeof(D));
		int head=0,tail=0;
		Q[tail++]=S;
		D[S]=0;
		for(;;){
			int i=Q[head++];
			for(edge* e=E[i];e;e=e->next){
				if(e->c==0)continue;
				int j=e->y;
				if(D[j]==-1){
					D[j]=D[i]+1;
					Q[tail++]=j;
					if(j==T)return;
				}
			}
			if(head==tail)break;
		}
	}
	edge* cur[MAXN];
	edge* path[MAXN];
	int flow(){
		int res=0; 
		int path_n;
		for(;;){
			DFS();
			if(D[T]==-1)break;
			memcpy(cur,E,sizeof(E));
			path_n=0;
			int i=S;
			for(;;){
				if(i==T){ 
					int mink=0;
					int delta=INT_MAX;
					for(int k=0;k<path_n;++k){
						if(path[k]->c < delta){
							delta = path[k]->c;
							mink=k;
						}
					}
					for(int k=0;k<path_n;++k){
						path[k]->c -= delta;
						path[k]->back->c += delta;
					}
					path_n=mink; 
					i=path[path_n]->x;
					res+=delta;
				}
				edge* e;
				for(e=cur[i];e;e=e->next){
					if(e->c==0)continue;
					int j=e->y;
					if(D[i]+1==D[j])break; 
				}
				cur[i]=e;
				if(e){
					path[path_n++]=e;
					i=e->y;
				}
				else{ 
					D[i]=-1;
					if(path_n==0)break;
					path_n--;
					i=path[path_n]->x;
				}
			}
		}
		return res;
	}
	int cut(int* s){
		int rst=0;
		for(int i=0;i<MAXN;++i)
			if(D[i]==-1&&E[i])
				s[rst++]=i;
		return rst;
	}
	void init(int _S,int _T){
		S=_S,T=_T;
		data=(edge*)storage; 
		memset(E,0,sizeof(E));
	}
	void add_edge(int x,int y,int w){
		E[x]=new((void*)data++) edge(x,y,w,E[x]);
		E[y]=new((void*)data++) edge(y,x,0,E[y]);
		E[x]->back = E[y];
		E[y]->back = E[x];
	}
} nico;

struct pt{
    int x, y, z;
} a[MAXM];

void solve(int casi){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);
    }
    sort(a + 1, a + m + 1, [](const pt& a, const pt& b) {
        return a.z < b.z;
    });
    int L = n - 1, R = m + 1;
    while (L + 1 < R) {
        int M = (L + R) / 2;
        nico.init(0, 2 * n + 1);
        for (int i = 1; i <= n; i++) nico.add_edge(0, i, 1);
        for (int i = 1; i <= n; i++) nico.add_edge(n + i, 2 * n + 1, 1);
        for (int i = 1; i <= M; i++) {
            nico.add_edge(a[i].x, n + a[i].y, a[i].z);
        }
        if (nico.flow() == n) R = M;
        else L = M;
    }
    if (R != m + 1) {
        printf("%d\n", a[R].z);
        return ;
    }
    puts("-1");
}

int main(){
    int T = 1;
    for (int i = 1; i <= T; i++)
        solve(i);
    return 0;
}