#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N,a[400010];
int r[400010],ans[400010];

bool bad(int mx,int now) {
    return now < (mx + 1) / 2;
}

int T[1801110];
void build(int x,int L,int R) {
    if (L == R) {
        T[x] = a[L];
        return;
    }
    int mid = (L + R) / 2;
    build(x*2,L,mid);
    build(x*2+1,mid+1,R);
    T[x] = max(T[x*2],T[x*2+1]);
}
int getmax(int x,int L,int R,int ql,int qr) {
    if (ql == L && qr == R) {
        return T[x];
    }
    int mid = (L + R) / 2;
    if (qr <= mid) {
        return getmax(x*2,L,mid,ql,qr);
    } else if (ql > mid) {
        return getmax(x*2+1,mid+1,R,ql,qr);
    } else {
        return max(getmax(x*2,L,mid,ql,mid),getmax(x*2+1,mid+1,R,mid+1,qr));
    }
}

int main() {
    scanf("%d",&N);
    for (int i=1;i<=N;i++) {
        scanf("%d",&a[i]);
        a[i + N] = a[i];
        a[i + 2*N] = a[i];
    }
    a[3 * N + 1] = -1;
    build(1,1,3*N+1);
    int mx = a[1];
    for (int i=2;i<=3*N+1;i++) {
        if (bad(mx,a[i])) {
            r[1] = i;
            break;
        }
        mx = max(mx, a[i]);
    }
    for (int i=2;i<=N;i++) {
        r[i] = r[i-1];
        while(i == r[i] || !bad(getmax(1,1,3*N+1,i,r[i]-1), a[r[i]])) {
            r[i]++;
        }
    }
    for (int i=1;i<=N;i++) {
        if (r[i] == 3 * N + 1) {
            ans[i] = -1;
        } else {
            ans[i] = r[i] - i;
        }
    }
    for (int i=1;i<=N;i++) {
        printf("%d%c",ans[i]," \n"[i==N]);
    }
}