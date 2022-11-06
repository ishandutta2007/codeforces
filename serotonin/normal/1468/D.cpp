#include<bits/stdc++.h>
using namespace std;
int t,n,m,o,a,b,i,z[200008];
int main() {
    for(scanf("%d",&t); t--; printf("%d\n",min(n,o-1)),i=0) {
        for(scanf("%d%d%d%d",&n,&m,&a,&b); i!=m; scanf("%d",z+i++));
        for(sort(z,z+m),o=abs(a-b),a<b?--b:b=n-b,--m,n=a=0; ~m; ~m?(--m,++n):0)
            for(++a; ~m&&b<a+z[m]; --m);
    }
    exit(0);
}