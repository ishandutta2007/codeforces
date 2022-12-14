#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[1000000];
int mx[1000000][21];
int len[1000000];
int b[1000000];
int get(int l,int r){
    return max(mx[l][b[r-l+1]],mx[r-len[r-l+1]+1][b[r-l+1]]);
}
int n,m;
int B[1000000];
int best(int i) {
    int ret=0;
    int l=1,r=n;
    while(l<=r) {
        int mid = (l+r)/2;
        int j = i+mid-1;
        if (j>n)r=mid-1;
        else if (get(i,j)<=B[mid])ret=mid,l=mid+1;
        else r=mid-1;
    }
    return ret;
}
int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    scanf("%d",&t);
    int cl = 1;
    int cb = 0;
    for (int i=1;i<=4e5;i++) {
        while(cl*2<=i)cl=cl*2,cb++;
        len[i]=cl;
        b[i]=cb;
    }
    while(t--) {
        scanf("%d",&n);
        for (int i=1;i<=20;i++)
            for (int j=1;j<=n;j++)
                mx[j][i]=0;
        for (int i=1;i<=n;i++) {
            B[i]=0;
            scanf("%d",&a[i]);
            mx[i][0]=a[i];
        }
        for (int i=1;i<=20;i++) {
            for (int j=1;j<=n;j++) {
                mx[j][i]=max(mx[j][i-1],mx[j+(1<<(i-1))][i-1]);
            }
        }
        scanf("%d",&m);

        for (int i=0;i<m;i++) {
            int p,s;
            scanf("%d%d",&p,&s);
            B[s]=max(B[s],p);
        }
        for (int i=n-1;i>=0;i--){
            B[i]=max(B[i],B[i+1]);
        }
        int ans=0;
        for (int i=1;i<=n;) {
            int cur = best(i);
            if (cur==0) {
                ans=-1;
                break;
            }
            ans++;
            i+=cur;
        }
        printf("%d\n",ans);
    }
}