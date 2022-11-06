#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=2e4+5;

int a[10000];

int main()
{
    int n,r,i,j,k,x;
    cin >> n >> r;
    memset(a,0,sizeof a);
    for(i=0;i<n;i++) scanf("%d", &a[i]);
    int s=r-1,l=0,ans=0;
    int flag=1;
    for(;;) {
        for(i=s;i>=l;i--) {
            if(a[i]) break;
        }
        x=i;
        if(x==l-1) {
            flag=0;
            break;
        }
        ans++;
        if(x+r>=n) break;
        s=x+2*r-1;
        l=x+1;
    }
    if(flag) printf("%d\n", ans);
    else puts("-1");
}