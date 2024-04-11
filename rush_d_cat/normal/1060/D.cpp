#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long LL;
const int N = 100000 + 10;
map< pair< pair<int,int>,int >, int > ban;
struct Nod{
    int l,r,id;
} nod[N]; 
struct cmp1 {
    bool operator()(const Nod &A, const Nod& B) {
        if(A.l==B.l) return A.id<B.id;
        return A.l < B.l;
    }
};
struct cmp2 {
    bool operator()(const Nod &A, const Nod& B) {
        if(A.r==B.r) return A.id<B.id;
        return A.r < B.r;
    }
};
int n;
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d%d",&nod[i].l,&nod[i].r);nod[i].id=i;
    }

    set<Nod,cmp1> q1; for(int i=1;i<=n;i++) q1.insert(nod[i]);
    set<Nod,cmp2> q2; for(int i=1;i<=n;i++) q2.insert(nod[i]);
    
    LL ans = n;
    for(int i=1;i<=n;i++) {
        Nod A = *q1.begin();
        Nod B = *q2.begin();

        q1.erase(A);q2.erase(B);
        //printf("A[%d,%d]%d B[%d,%d]%d\n", A.l,A.r,A.id,B.l,B.r,B.id);
        if(A.id == B.id) {
            ans += max(A.l, A.r); 
            continue;
        }
        q1.erase(B);q2.erase(A);
        Nod tmp; tmp.l = B.l, tmp.r = A.r; tmp.id = B.id; 
        ans += max(B.r, A.l);
        q1.insert(tmp); q2.insert(tmp);
    }
    cout << ans << endl;

}