#include <iostream>
#include <cstdio>
#include<algorithm>
#include<cstring>
#include<set>
#include<map>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

const int N = 500005;

int a[N];
int R[N],L[N];

int main() {
    int n;
    scanf("%d",&n);
    fo(i,1,n)scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    fo(i,1,n){
        R[i]=R[i-1];
        while(R[i]<n&&a[R[i]+1]<a[i]*2)R[i]++;
    }
    L[0]=0;
    fo(i,1,n){
        L[i]=L[i-1];
        while(L[i]<n&&a[L[i]+1]*2<=a[i])L[i]++;
    }
    int mv=1e9;
    int ans=0;
    fo(i,1,n){
        mv=min(mv,i-R[i]);
        int tmp=i-L[i]+1-n-mv;
        ans=max(ans,tmp);
    }
    ans=n-ans;
    ans=n-ans/2;
    printf("%d\n",ans);
    return 0;
}