#include <cmath>
#include <cstdio>
#include <algorithm>
const int Maxn=300;
typedef long double ld;
const ld eps=1e-9;
struct Node{
    ld x,y;
    Node(ld _x=0,ld _y=0){
        x=_x,y=_y;
    }
    friend Node operator +(Node a,Node b){
        return Node(a.x+b.x,a.y+b.y);
    }
    friend Node operator -(Node a,Node b){
        return Node(a.x-b.x,a.y-b.y);
    }
    friend Node operator *(Node a,ld b){
        return Node(a.x*b,a.y*b);
    }
    friend Node operator /(Node a,ld b){
        return Node(a.x/b,a.y/b);
    }
    friend ld operator *(Node a,Node b){
        return a.x*b.x+a.y*b.y;
    }
    friend ld operator /(Node a,Node b){
        return a.x*b.y-a.y*b.x;
    }
    ld find_deg(){
        return atan2(y,x);
    }
    ld find_dis(){
        return sqrt(x*x+y*y);
    }
    Node find_bot(){
        return Node(-y,x)/find_dis();
    }
};
struct Line{
    Node s,v;
    ld deg;
    Line(Node _s=Node(),Node _v=Node()){
        s=_s,v=_v;
        deg=v.find_deg();
    }
    friend Node operator *(Line a,Line b){
        return a.s+a.v*(b.v/(a.s-b.s)/(a.v/b.v));
    }
    friend bool operator <(Line a,Line b){
        if(fabsl(a.deg-b.deg)>=eps){
            return a.deg<b.deg;
        }
        return a.v/(b.s-a.s)>0;
    }
};
int n;
int x[Maxn+5],y[Maxn+5];
int p[Maxn<<1|5],nxt[Maxn+5];
Line edge[Maxn<<1|5];
Node ans_a[2];
bool vis[Maxn<<1|5];
Line q_1[Maxn<<1|5];
Node q_2[Maxn<<1|5];
int l,r;
bool solve(int l_b,int r_b){
    for(int i=1;i<=n;i++){
        vis[i]=1;
        vis[n+i]=0;
    }
    for(int i=l_b;i<=r_b;i++){
        vis[n+(i-1)%n+1]=1;
    }
    l=1,r=0;
    for(int i=1;i<=(n<<1);i++){
        if(vis[p[i]]){
            Line now=edge[p[i]];
            while(l<r&&now.v/(q_2[r]-now.s)<eps){
                r--;
            }
            while(l<r&&now.v/(q_2[l+1]-now.s)<eps){
                l++;
            }
            if(l<=r&&fabsl(q_1[r].deg-now.deg)<eps){
                q_1[r]=now;
            }
            else{
                q_1[++r]=now;
            }
            if(l<r){
                q_2[r]=q_1[r-1]*now;
            }
        }
    }
    Line now=q_1[l];
    while(l<r&&now.v/(q_2[r]-now.s)<eps){
        r--;
    }
    if(r-l+1<=2){
        return 0;
    }
    return 1;
}
Node ans_l[Maxn+5];
bool cmp_Edge(int a,int b){
    return edge[a]<edge[b];
}
bool check(ld R){
    for(int i=1;i<=n;i++){
        edge[n+i]=Line(edge[i].s+edge[i].v.find_bot()*R,0-edge[i].v);
    }
    std::sort(p+1,p+1+(n<<1),cmp_Edge);
    for(int i=1,j=1;i<=n;i++){
        while(j<i+n-1&&solve(i,j+1)){
            j++;
        }
        solve(i,nxt[i]=j);
        ans_l[i]=q_2[r];
    }
    for(int i=1;i<=n;i++){
        int dis=nxt[i]-i+1,j=nxt[i]%n+1;
        dis+=nxt[j]-j+1;
        if(dis>=n){
            ans_a[0]=ans_l[i];
            ans_a[1]=ans_l[j];
            return 1;
        }
    }
    return 0;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&x[i],&y[i]);
    }
    for(int i=1;i<=n;i++){
        edge[i]=Line(Node(x[i],y[i]),Node(x[i%n+1],y[i%n+1])-Node(x[i],y[i]));
    }
    for(int i=1;i<=(n<<1);i++){
        p[i]=i;
    }
    ld left=0,right=2e4;
    while(right-left>eps){
        ld mid=(left+right)/2;
        if(check(mid)){
            right=mid;
        }
        else{
            left=mid;
        }
    }
    check(left);
    printf("%.10lf\n",(double)(left+eps));
    printf("%.10lf %.10lf\n",(double)(ans_a[0].x),(double)(ans_a[0].y));
    printf("%.10lf %.10lf\n",(double)(ans_a[1].x),(double)(ans_a[1].y));
    return 0;
}