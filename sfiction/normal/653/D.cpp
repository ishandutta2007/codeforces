#include <climits>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN=60,MAXM=1000;
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
}dinic;

const int MAXMM = 5E2 + 10;

int n, m, X;
int u[MAXMM], v[MAXMM], c[MAXMM];

int main(){
	scanf("%d%d%d", &n, &m, &X);
	for (int i = 0; i < m; ++i){
		scanf("%d%d%d", &u[i], &v[i], &c[i]);
		--u[i], --v[i];
	}
	double high = (m + 1) * 1E6, low = 1E-7, mid;
	for (int i = 0; i < 100; ++i){
		mid = (high + low) / 2;

//		printf("%.12f\n", mid);

		dinic.init(0, n - 1);
		for (int j = 0; j < m; ++j){
			dinic.add_edge(u[j], v[j], mid * X <= c[j] ? X : (int)(c[j] / mid));
		}

		if (dinic.flow() >= X)
			low = mid;
		else
			high = mid;
	}
	printf("%.10f\n", low * X);
	return 0;
}