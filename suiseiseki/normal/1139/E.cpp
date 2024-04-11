#include <cstdio>
#include <cstring>
struct edge{
    int n,nxt;
    edge(int n,int nxt){
        this->n=n;
        this->nxt=nxt;
    }
    edge(){}
}e[5005];
int head[5005],ecnt=-1;
void add(int from,int to){
    e[++ecnt]=edge(to,head[from]);
    head[from]=ecnt;
}
int s[5005];
bool used[5005];
bool Find(int x){
    if(used[x]){
    	return 0;
	}
    used[x]=1;
    for(int i=head[x];~i;i=e[i].nxt){
    	if(s[e[i].n]==-1||Find(s[e[i].n])){
    		s[e[i].n]=x;
    		return 1;
		}
	}
    return 0;
}
int a[5005],b[5005],c[5005];
int ans[5005];
int main(){
    memset(head,-1,sizeof(head));
    memset(s,-1,sizeof(s));
    int n,m,q;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
    	scanf("%d",&a[i]);
	}
    for(int i=1;i<=n;i++){
    	scanf("%d",&b[i]);
	}
    scanf("%d",&q);
    for(int i=1;i<=q;i++){
        scanf("%d",&c[i]);
        used[c[i]]=1;
    }
    for(int i=1;i<=n;i++){
    	if(!used[i]){
    		add(a[i],b[i]);
		}
	}
    int t=0;
    for(int i=q;i>0;i--){
        memset(used,0,sizeof(used));
        while(Find(t)){
            ++t;
            memset(used,0,sizeof(used));
        }
        ans[i]=t;
        add(a[c[i]],b[c[i]]);
    }
    for(int i=1;i<=q;i++){
    	printf("%d\n",ans[i]);
	}
    return 0;
}