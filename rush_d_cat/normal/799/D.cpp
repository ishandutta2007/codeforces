#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 100000+10;
int a,b,h,w,n;LL m[N],A,B;
bool cmp(int x,int y){
    return x>y;
}

vector<int> bu;
vector<LL> v1,v2;
bool check(int k, LL M) {
    v1.clear(); v2.clear();bu.clear();

    int mid=(1+k)>>1;
    for(int i=1;i<=mid;i++) bu.push_back(m[i]);

    for(int i=0;i<1<<bu.size();i++) {
        LL mm = 1;
        for(int bit=0;bit<bu.size();bit++){
            if(i>>bit&1) mm *= bu[bit];
        }
        v1.push_back(mm);
    }

    bu.clear();
    for(int i=mid+1;i<=k;i++) bu.push_back(m[i]);
    for(int i=0;i<1<<bu.size();i++) {
        LL mm = 1;
        for(int bit=0;bit<bu.size();bit++){
            if(i>>bit&1) mm *= bu[bit];
        }
        v2.push_back(mm);
    }
    sort(v2.begin(),v2.end()); v2.push_back(1e18);
    for(auto x: v1) {
        LL y = *lower_bound(v2.begin(),v2.end(),((A+(x-1))/x));
        if(y==1e18) continue;
        LL other = M/(y*x);
        if(other >= B) return 1;  
    }
    return 0;
}
int solve() {
    if(h>=a && w>=b) return 0;

    int mx = min(n, 34);
    A=(a+h-1)/h, B=(b+w-1)/w;
    LL M=1;
    for(int i=1;i<=mx;i++) 
    {
        M*=m[i];
        if(M>=A*B)
        {
            if(check(i,M)) return i;
        }
    }
    return -1;
}
int main() {
    scanf("%d%d%d%d%d",&a,&b,&h,&w,&n);
    for(int i=1;i<=n;i++) scanf("%lld",&m[i]);
    sort(m+1,m+1+n,cmp);
    int a1 = solve(); swap(h,w); int a2 = solve();

    if(a1==-1 && a2==-1) return !printf("-1\n");
    printf("%d\n", min(a1,a2));

}