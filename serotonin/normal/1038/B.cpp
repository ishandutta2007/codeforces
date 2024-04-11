#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=1e5+5;

int main()
{
    int n,i;
    cin >> n;
    if(n==1 || n==2) {
        puts("No");
        return 0;
    }
    puts("Yes");
    if(n==3) {
        printf("1 2\n");
        printf("2 1 3\n");
        return 0;
    }
    if(n==4) {
        printf("2 1 3\n");
        printf("2 2 4\n");
        return 0;
    }
    printf("%d", n/2);
    for(i=1;i<=n/2;i++) printf(" %d", i);
    puts("");
    printf("%d", n-n/2);
    for(i=n/2+1;i<=n;i++) printf(" %d", i);
    puts("");
}