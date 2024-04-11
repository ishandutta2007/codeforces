#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;
using std::vector;
typedef long long ll;
const int c=2e5+5;
vector <int> ofc[c];
int k,t,ans,d=1;
int trav[c],pos[c],last[c];


void dfs(int u)
{
    int i,x;
    for(i=0;i<ofc[u].size();i++) {
        x=ofc[u][i];
        d++;
        trav[d]=x;
        pos[x]=d;
        dfs(x);
    }
    last[u]=trav[d];

}

int main()
{
    int n,q,i,j,x,u;
    cin>>n>>q;
    for(i=2;i<=n;i++) {
        scanf("%d", &x);
        ofc[x].push_back(i);
    }
    trav[1]=1;
    pos[1]=1;
    dfs(1);

    /*for(i=1;i<=n;i++) printf("%d ", trav[i]);
    puts("");
    for(i=1;i<=n;i++) printf("%d ", last[trav[i]]);*/

    for(j=0;j<q;j++) {
        scanf("%d %d", &u, &k);

        if(pos[last[u]]-pos[u]+1 < k) cout<<-1<<endl;
        else {
            x=trav[pos[u]+k-1];
            cout<<x<<endl;
        }
    }
}