#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
using namespace std;

int t,n;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int ans=0;
        for(int i=0;i<9;i++){
            vector<int> v1,v2;
            for(int x=1;x<=n;x++){
                if(x>>i&1) v1.push_back(x);
                else v2.push_back(x);
            }
            
            if(v1.size() && v2.size()) {
                printf("%d %d", v1.size(),v2.size());
                for(auto x: v1) printf(" %d", x);
                for(auto x: v2) printf(" %d", x);
                printf("\n");
                fflush(stdout);
                int tmp; scanf("%d",&tmp);ans=max(ans,tmp);
            }
        }
        printf("-1 %d\n", ans); fflush(stdout);
    }
}