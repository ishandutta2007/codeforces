//#pragma comment(linker,"/STACK:16777216")
#include <iostream> 
#include <vector>
#include <set>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

#define FOR(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define MP make_pair
#define ALL(a) ((a).begin(),(a).end())
#define PB push_back
#define PII pair<int,int>
#define CLEAR(a) memset((a),0,sizeof((a)))
#define X first
#define Y second

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;

const double pi=3.141592653589793;

int main(){
    int m,n,l,k;
    cin>>n>>m;
    VI g[101];
    FOR(i,0,m)
    {
        cin>>k>>l;
        g[k-1].PB(l-1);
        g[l-1].PB(k-1);
    }
    bool q=1;k=0;
    VI a;
    while (q)
    {
        a.clear();
        FOR(i,0,n)
            if(g[i].size()==1)
                a.PB(i);
        FOR(i,0,a.size())
            if (g[a[i]].size()!=0)
            {
                FOR(j,0,g[g[a[i]][0]].size()-1)
                    if (g[g[a[i]][0]][j]==a[i]) swap(g[g[a[i]][0]][j],g[g[a[i]][0]][g[g[a[i]][0]].size()-1]);
                g[g[a[i]][0]].pop_back();
                g[a[i]].pop_back();
            }
        if (a.empty()) q=0; else
        k++;
        /*FOR(i,0,n)
        {
            FOR(j,0,g[i].size())
                cout<<i<<'-'<<g[i][j]<<' ';
            cout<<endl;
        }*/
    }
    cout<<k;
    return 0;
}