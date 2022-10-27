#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N=100000+10;
int bit[2][N],n;
vector<int> vec[1002];
void add(int id,int x){
    while(x<N){
        bit[id][x]++; x+=x&(-x);
    }
}
int sum(int id,int x){
    int ans=0;
    while(x>0){
        ans+=bit[id][x];
        x -= x&(-x);
    }
    return ans;
}

int ans=0;
void solve(int x) {
    int c1 = x+1; if(c1>n) c1=1;
    int c2 = x-1; if(c2<1) c2=n;
    for(int i=0;i<N;i++)
        bit[0][i]=bit[1][i]=0;
    for(auto x: vec[c1])
        add(0, x);
    for(auto x: vec[c2])
        add(1, x);
    for(int i=0;i+1<vec[x].size();i++){
        if(sum(0,vec[x][i+1]) - sum(0,vec[x][i]-1)
            != sum(1,vec[x][i+1]) - sum(1,vec[x][i]-1)) {
            //printf("x=%d, [%d,%d]\n", x,vec[x][i],vec[x][i+1]);
            ans ++;
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int sz; scanf("%d",&sz);
        for(int j=1;j<=sz;j++) {
            int x; scanf("%d",&x);
            vec[i].push_back(x);
        }
        sort(vec[i].begin(), vec[i].end());
    }
    for(int i=1;i<=n;i++) solve(i);
    cout << ans << endl;
}