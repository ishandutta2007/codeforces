#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
const int N = 200000 + 10;
int n,M,t[N],c[N];

int main() {
    scanf("%d%d",&n,&M);
    for(int i=1;i<=n;i++) scanf("%d",&t[i]);
    int sum=0;
    for(int i=1;i<=n;i++){
        int ans=0;
        int tmpsum = sum;
        for(int j=100;j>=0;j--) {
            if(tmpsum+t[i] <= M) break;
            if(tmpsum+t[i]-c[j]*j > M) {
                ans += c[j]; tmpsum -= c[j]*j;
                //if(c[j])printf("j=%d, c=%d\n", j,c[j]);
            } else {
                int det = tmpsum+t[i]-M;
                ans += (det + j-1) / j;
                break;
            }
        }
        printf("%d ", ans);
        c[t[i]]++; sum+=t[i];
    }
}