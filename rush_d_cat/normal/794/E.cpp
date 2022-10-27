#include <iostream>
#include <algorithm>
using namespace std;
const int N=300002;
int n,a[N],b[N],res[N];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    int mx = *max_element(a+1,a+1+n);
    for(int i=1;i<=n;i++)b[i]=min(a[i],max(a[i-1],a[i+1]));

    if(n%2==0) {
        int ans1=0,ans2=0;
        int l=n/2,r=n/2+1;
        for(int i=1;i<=n/2;i++) {
            ans2=max(max(b[l],b[r]),ans2);
            res[2*i-1] = ans2;
            ans1=max(max(a[l--],a[r++]), ans1);
            res[2*(i-1)] = ans1;
        }
        res[n-1]=mx;
    } else {
        int ans1=a[(n+1)/2],ans2=0;
        int l=(n+1)/2,r=(n+1)/2;
        for(int i=1;i<=n/2;i++){
            ans2=max(ans2,max(b[l],b[r]));
            res[2*i-2]=ans2;
            ans1=max(ans1,max(a[--l],a[++r]));
            res[2*i-1]=ans1;
        }
        res[n-1]=mx;
    }
    for(int i=0;i<n;i++)
        printf("%d ", res[i]);
}

/*

#######

5
1 2 3 2 1

*/