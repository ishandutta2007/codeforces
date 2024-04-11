#include <iostream>
#include <vector>
#include <cmath>
typedef long long LL;
using namespace std;
int a,b;
vector< pair<int,int> > v[2002];
int main(){
    for(int i=1;i<=1000;i++){
        for(int j=1;j<=1000;j++){
            if(i==j) continue;
            int k=i*i+j*j;
            int s=(int)(sqrt(k)+0.5);
            if(s*s==k) {
                v[s].push_back(make_pair(i,j));
            }
        }
    }

    cin>>a>>b;
    if(a>b) swap(a,b);
    
    for(auto p: v[a]) {
        int x=p.first, y=p.second;
        if(x*b%a == 0 && y*b%a==0) {
            printf("YES\n");
            printf("%d %d\n", 0,0);
            printf("%d %d\n", -y,x);
            printf("%d %d\n", (b*x/a), (b*y/a));
            return 0;
        }
    }
    printf("NO\n");
}