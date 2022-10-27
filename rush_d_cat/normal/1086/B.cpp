#include <iostream>
using namespace std;

const int N = 100000+10;
int n,s,d[N]; 
int main(){
    scanf("%d%d",&n,&s);
    for(int i=1;i<n;i++){
        int u,v; scanf("%d%d",&u,&v);
        d[u]++, d[v]++;
    }
    int c=0;
    for(int i=1;i<=n;i++) if(d[i]==1) c++;
    printf("%.9f\n", s*2.0/c);
}