#include <iostream>
using namespace std;
typedef long long LL;
const int N=102;
int n,r,cnt[N];
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&r);
        for(int x=1;x<=r;x++){
            int v;scanf("%d",&v);cnt[v]++;
        }
    }
    for(int i=1;i<=100;i++)
        if(cnt[i]==n)printf("%d ", i);
}