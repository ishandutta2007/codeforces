#include <stdio.h>
#include <algorithm>
using namespace std;
#define M 3000001

int f[M],x[M],y[M],id[M],ID[M],w[M],match[M];

bool cmp(int a,int b) {
    if(y[a]-x[a]!=y[b]-x[b]) return y[a]-x[a]<y[b]-x[b];
    return y[a]<y[b];
}

bool cmp2(int a,int b) {
    if(w[a]!=w[b]) return w[a]<w[b];
    return a<b;
}

int calc(int a) {
    int tp = 100000000;
    while(a) {
        tp=min(tp,f[a]);
        a-=(a&-a);
    }
    return tp;
}

void add(int a,int b) {
    while(a<M) {
        f[a] = min(f[a],b);
        a+=a&-a;
    }
}

int main() {
    ///freopen("2.in","r",stdin);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d %d",&x[i],&y[i]);
    for(int i=0;i<n;i++) id[i] = i;
    sort(id,id+n,cmp);
    for(int i=0;i<n;i++) scanf("%d",&w[i]);
    for(int i=0;i<n;i++) ID[i] = i;
    sort(ID,ID+n,cmp2);
    for(int i=0;i<n;i++) {
        if(w[ID[i]] != y[id[i]] - x[id[i]]) {puts("NO");exit(0);}
        ///match[id[i]] = ID[i];
        match[ID[i]] = id[i];
    }
    for(int i=0;i<M;i++) f[i] = 100000000;
    for(int i=n-1;i>=0;i--) {
        int a = match[i];
        int b = calc(y[a] + 200001);
        if(b<=x[a]) {puts("NO");exit(0);}
        add(y[a]+200001,x[a]);
    }
    puts("YES");
    for(int i=0;i<n;i++) {
        printf("%d %d\n",x[match[i]],y[match[i]]);
    }
}