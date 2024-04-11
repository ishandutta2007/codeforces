#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#define MAXN 310000
using namespace std;
struct gt{
    int x,y;
    inline gt(int a=0,int b=0){x=a;y=b;}
    inline bool operator <(const gt &a)const{
        if(a.x==x)return y<a.y;else return x<a.x;
    }
};
typedef set<gt>::iterator it;
set<gt> S;multiset<int>res;
int n,N;int a[MAXN],b[MAXN],c[MAXN],fa[MAXN],fb[MAXN],fc[MAXN],q[MAXN];
struct po{int x,y,z;}ans[MAXN];
inline int get(int x){return lower_bound(q+1,q+1+N,x)-q;}
inline bool cmp(const po &x,const po &y){return x.x>y.x;}
int flag[MAXN];
inline void in(int x,int y){
    if(x>n||y>n)return;
    flag[x+y]++;
    if(flag[x+y]==1)res.insert(x+y);
}
inline void er(int x,int y){
    if(x>n||y>n)return;
    flag[x+y]--;
    if(flag[x+y]==0)res.erase(x+y);
}
inline void Add(it t1){
    gt std=gt(0,0);
    gt nxt,pre;
    if(t1==S.begin())pre=std;else {pre=*(--t1);t1++;}
    if(++t1==S.end())nxt=std;else nxt=*t1;t1--;
    
    er(pre.x,nxt.y);
    in(pre.x,(*t1).y);
    in((*t1).x,nxt.y);
}
inline void Del(it t1){
    gt std=gt(0,0);
    gt nxt,pre;
    if(t1==S.begin())pre=std;else {pre=*(--t1);t1++;}
    if(++t1==S.end())nxt=std;else nxt=*t1;t1--;
    
    in(pre.x,nxt.y);
    er(pre.x,(*t1).y);
    er((*t1).x,nxt.y);
    S.erase(t1);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){scanf("%d",&a[i]);q[++q[0]]=a[i];}
    for(int i=1;i<=n;i++){scanf("%d",&b[i]);q[++q[0]]=b[i];}
    for(int i=1;i<=n;i++){scanf("%d",&c[i]);q[++q[0]]=c[i];}
    sort(q+1,q+1+q[0]);
    N=unique(q+1,q+1+q[0])-q-1;
    for(int i=1;i<=n;i++){a[i]=get(a[i]);b[i]=get(b[i]);c[i]=get(c[i]);}
    memset(fa,63,sizeof fa);memset(fb,63,sizeof fb);memset(fc,63,sizeof fc);
    for(int i=n;i>=1;i--)fa[a[i]]=i;
    for(int i=n;i>=1;i--)fb[b[i]]=i;
    for(int i=n;i>=1;i--)fc[c[i]]=i;
    for(int i=1;i<=N;i++)ans[i]=(po){fa[i],fb[i],fc[i]};
    sort(ans+1,ans+1+N,cmp);
    int Res=21333333;
    if(ans[1].x<=n)Res=ans[1].x;
    gt tmp;
    for(int i=1;i<=N;i++){
        tmp=gt(ans[i].y,ans[i].z);
        it t1=S.upper_bound(tmp);
        if(t1==S.end()||t1->y<tmp.y){
            if(t1!=S.begin()){
                --t1;
                while(t1->y<=tmp.y){
                    if(t1==S.begin()){Del(t1);break;}
                    Del(t1--);
                }
            }
            S.insert(tmp);
            Add(S.lower_bound(tmp));
        }
        if(res.begin()!=res.end())
        Res=min(Res,(*res.begin())+ans[i+1].x);
    }
    printf("%d\n",Res);
    return 0;
}