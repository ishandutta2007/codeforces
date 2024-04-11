#include <climits>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>

#define st first
#define nd second

using namespace std;

typedef pair<int, int> PII;

const int MAXNN = 1E4 + 10;

int n, b, q;
PII a[MAXNN];
int c[MAXNN][5];

const int MAXN=22000,MAXM=440000;

struct Dinic{
    struct edge{
        int x,y;//
        int c;//
        int f;//
        edge *next,*back;//
        edge(int x,int y,int c,edge* next):x(x),y(y),c(c),f(0),next(next),back(0){}
        void* operator new(size_t, void *p){return p;}
    }*E[MAXN],*data;//E[i]i
    char storage[2*MAXM*sizeof(edge)];
    int S,T;//
   
    int Q[MAXN];//DFSqueue
    int D[MAXN];//-1
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
    edge* cur[MAXN];//
    edge* path[MAXN];//
    int flow(){
        int res=0;//
        int path_n;//path
        for(;;){
            DFS();
            if(D[T]==-1)break;
            memcpy(cur,E,sizeof(E));
            path_n=0;
            int i=S;
            for(;;){
                if(i==T){//
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
                    path_n=mink;//
                    i=path[path_n]->x;
                    res+=delta;
                }
                edge* e;
                for(e=cur[i];e;e=e->next){
                    if(e->c==0)continue;
                    int j=e->y;
                    if(D[i]+1==D[j])break;//
                }
                cur[i]=e;//
                if(e){
                    path[path_n++]=e;
                    i=e->y;
                }
                else{//
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
    void add_edge(int x,int y,int w){//xyw0<=x,y<MAXN0<w<=INT_MAX
        E[x]=new((void*)data++) edge(x,y,w,E[x]);
        E[y]=new((void*)data++) edge(y,x,0,E[y]);
        E[x]->back = E[y];
        E[y]->back = E[x];
    }
};

Dinic dinic;

int main(){
	scanf("%d%d%d", &n, &b, &q);
	for (int i = 0; i < q; ++i)
		scanf("%d%d", &a[i].st, &a[i].nd);
	a[q].st = 0;
	a[q].nd = 0;
	a[q + 1].st = b;
	a[q + 1].nd = n;
	q += 2;
	sort(a, a + q);
	q = unique(a, a + q) - a;
	for (int i = 1; i < q; ++i)
		if (a[i].st == a[i - 1].st){
			puts("unfair");
			return 0;
		}
	for (int i = q - 1; i > 0; --i)
		if ((a[i].nd -= a[i - 1].nd) < 0){
			puts("unfair");
			return 0;
		}

	int S = 0, T = 5 + q;
	dinic.init(S, T);
	for (int i = 0; i < 5; ++i)
		dinic.add_edge(S, i + 1, n / 5);
	for (int i = q - 1; i > 0; --i)
		for (int j = 0; j < 5; ++j)
			c[i][j] = (a[i].st + 4 - j) / 5;
	for (int i = q - 1; i > 0; --i){
		for (int j = 0; j < 5; ++j){
			dinic.add_edge(j + 1, i + 5, c[i][j] - c[i - 1][j]);
//			printf("%d %d %d\n", j + 1, i + 5, c[i][j] - c[i - 1][j]);
		}
		dinic.add_edge(5 + i, T, a[i].nd);
//		printf("%d\n", a[i].nd);
	}
	puts(dinic.flow() == n ? "fair" : "unfair");
	return 0;
}