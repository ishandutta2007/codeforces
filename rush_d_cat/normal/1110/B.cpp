#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <queue>
using namespace std;
typedef long long LL;

const int N = 100000 + 10;
int n,m,k,b[N];

int main() {
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&b[i]);
    }
    priority_queue<int> q;
    for(int i=2;i<=n;i++){
        q.push(b[i]-b[i-1]-1);
    }
    int ans=b[n]-b[1]+1;
    for(int i=1;i<k;i++){
        if(q.size()){
            ans -= q.top(); q.pop();
        }
    }
    printf("%d\n", ans);
}