#include <iostream>
using namespace std;
const int N = 1000000+10;
int bit[N];
void add(int x) {
    while (x < N) {
        bit[x] ++;
        x += x&(-x);
    }
}
int sum(int x) {
    int ans=0;
    while(x) {
        ans+=bit[x];
        x -= x&(-x);
    }
    return ans;
}
int a[N];
int main() {
    int n; scanf("%d", &n);
    long long ans = 0;
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        ans += (i-1)-sum(a[i]);
        add(a[i]);
    }
    if (n%2)
        printf("%s\n", (ans%2)?"Petr":"Um_nik");
    else
        printf("%s\n", (ans%2==0)?"Petr":"Um_nik");
}