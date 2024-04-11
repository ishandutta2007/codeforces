#include <iostream>
#include <set>
using namespace std;
const int N = 100000 + 10;
int n,cp[N],ans[N],vis[N];

int mpow(int a,int x){
    if(x==0) return 1;
    int t=mpow(a,x>>1);
    if(x%2==0) return 1LL*t*t%n;
    return 1LL*t*t%n*a%n;
}

int main() {
    cin>>n;
    if(n==1) {
        return !printf("YES\n1\n");
    }
    if(n==2) {
        return !printf("YES\n1\n2\n");
    }
    if(n==4) {
        return !printf("YES\n1\n3\n2\n4\n");
    }
    for(int i=2;i<n;i++) {
        if(n%i==0) return !printf("NO\n");
    }

    printf("YES\n");
    for(int i=2;i<=n-1;i++) {
        cp[i]=mpow(i,n-2);
    }

    ans[1]=1, ans[n]=n;
    int m=1;
    for(int i=2;i<n;i++){
        m=1LL*m*ans[i-1]%n;
        ans[i] = 1LL * i * mpow(m, n-2) % n;
    }
    for(int i=1;i<=n;i++) {
        printf("%d\n", ans[i]);
    }
}
/*
1 2 5 
*/