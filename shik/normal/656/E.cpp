#include <cstdio>
#include <algorithm>
using namespace std;

int n,a[10][10];

void fj( int i, int j ) {
    scanf("%d",&a[i][j]);
    j+1<n && (fj(i,j+1),0);
}

void fi( int i ) {
    fj(i,0);
    i+1<n && (fi(i+1),0);
}

void gi( int t ) {
    int k=t/n/n;
    int i=t/n%n;
    int j=t%n;
    a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
    t+1<n*n*n && (gi(t+1),0);
}

int main() {
    scanf("%d",&n);
    fi(0);
    gi(0);
    int ans=*max_element((int*)a,(int*)a+100);
    printf("%d\n",ans);
    return 0;
}