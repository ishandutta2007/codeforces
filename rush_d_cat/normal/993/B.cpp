#include <iostream>
#include <vector>
#include <set>
using namespace std;
int n,m;
struct Info {
    int x,y;
    void read() {
        scanf("%d %d", &x, &y);
        if(x>y) swap(x,y);
    }
} A[20], B[20];
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        A[i].read();
    for(int i=1;i<=m;i++)
        B[i].read();


    set<int> miao;
    for(int i=1;i<=n;i++){
        set<int> sam;
        for(int j=1;j<=m;j++){
            if(A[i].x==B[j].x && A[i].y == B[j].y) continue;
            if(A[i].x == B[j].x || A[i].x == B[j].y)
                sam.insert(A[i].x);
            if(A[i].y == B[j].x || A[i].y == B[j].y)
                sam.insert(A[i].y);
        }
        if(sam.size()>=2) {
            return !printf("-1\n");
        }
        if(sam.size()==1) miao.insert(*sam.begin());
    }

    for(int i=1;i<=m;i++){
        set<int> sam;
        for(int j=1;j<=n;j++){
            if(B[i].x == A[j].x && B[i].y == A[j].y) continue;
            if(B[i].x == A[j].x || B[i].x == A[j].y)
                sam.insert(B[i].x);
            if(B[i].y == A[j].x || B[i].y == A[j].y)
                sam.insert(B[i].y);
        }
        if(sam.size()>=2) {
            return !printf("-1\n");
        }
        if(sam.size()==1) miao.insert(*sam.begin());
    }

    if(miao.size()==0) return !printf("-1\n");
    if(miao.size()==1) return !printf("%d\n", *miao.begin());
    printf("0\n");
}