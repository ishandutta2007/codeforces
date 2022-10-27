#include <iostream>
#include <vector>
using namespace std;
const int N = 1002;
int n,m;
double w;
int a[N],b[N];
vector<int> todo;
bool chk(double x) {
    for(auto k: todo) {
        x = x - (x + w) / k;     
        //printf("%.5f\n", x);   
        if (x < 0) return 0;
    }
    return 1;
}
int main() {
    scanf("%d%lf",&n,&w);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    
    todo.push_back(a[1]);
    for(int i=2;i<=n;i++) {
        todo.push_back(b[i]); todo.push_back(a[i]);
    }
    todo.push_back(b[1]);
    //chk(0.0); return 0;
    double l=0.0, r=1e18;
    for(int i=1;i<=80;i++) {
        double mid=(l+r)/2;
        //printf("%.5f\n", mid);
        if(chk(mid)) {
            r=mid;
        } else {
            l=mid;
        }
    }
    if(!chk(1e18)) {
        printf("-1\n"); return 0;
    }
    printf("%.9f\n", l);
}