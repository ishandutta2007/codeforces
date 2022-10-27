#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N = 1000 + 10;
int MX,n,l[N],r[N],ll[N],rr[N],vis[N],a[N];
int L[N],R[N];
int main() {
    scanf("%d",&n); MX = n;
    for(int i=1;i<=n;i++) scanf("%d",&l[i]), ll[i]=l[i];
    for(int i=1;i<=n;i++) scanf("%d",&r[i]), rr[i]=r[i];

    for(int i=1;i<=n;i++) {
        vector<int> vec; vec.clear();
        int pos = 0;
        for(int x=1;x<=n;x++) {
            if(vis[x]) continue;
            if(l[x]==0 && r[x]==0) {
                pos = x; break;
            }
        }
        if(pos==0) continue;
        //printf("pos=%d\n", pos); 
        int flag[N]={0};
        a[pos]=MX;flag[pos]=1;
        for(int x=1;x<pos;x++) {
            if(vis[x]) continue;
            if(r[x]==0) {
                a[x]=MX;flag[x]=1;
                if(l[x]) return !printf("NO\n");
            } 
        }
        for(int x=pos+1;x<=n;x++){
            if(vis[x]) continue;
            if(l[x]==0) {
                a[x]=MX;flag[x]=1;
                if(r[x]) return !printf("NO\n");
            }
        }
        int cnt=0;
        for(int x=1;x<=n;x++) if(vis[x]==0) {
            if(flag[x]) cnt++;
            else l[x] -= cnt;
        }
        cnt=0;
        for(int x=n;x>=1;x--) if(vis[x]==0) {
            if(flag[x]) cnt++;
            else r[x] -= cnt;
        }
        for(int x=1;x<=n;x++) {
            if(flag[x]) {
                //printf("vis %d\n", x);
                vis[x]=1;
            }
        }
        //for(int x=1;x<=n;x++) printf("l=%d,r=%d\n", l[x],r[x]);
        MX --;
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<i;j++) if(a[j]>a[i]) L[i]++;
        for(int j=i+1;j<=n;j++) if(a[j]>a[i]) R[i]++;
        if(L[i]!=ll[i] || R[i]!=rr[i]) return !printf("NO\n");
    }
    printf("YES\n");
    for(int i=1;i<=n;i++) printf("%d ", a[i]);
}