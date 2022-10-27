#include <iostream>
#include <vector>
using namespace std;
const int N = 100000 + 10;
int n,m;
int f[N],b[N];
vector<int> v[N];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&f[i]);
        v[f[i]].push_back(i);
    }
    int state = 0;
    for(int i=1;i<=m;i++){
        scanf("%d",&b[i]);
        if(v[b[i]].size()==0) {
            state = -1; break;
        }
        if(v[b[i]].size()>=2) {
            state = +1; 
        }
    }
    if(state==1) return !printf("Ambiguity\n");
    if(state==-1)return !printf("Impossible\n");
    printf("Possible\n");
    for(int i=1;i<=m;i++)
        printf("%d ", v[b[i]][0]);
}