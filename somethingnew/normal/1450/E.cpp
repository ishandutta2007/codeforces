#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#define f first
#define s second
#define all(x) (x).begin(), (x).end()
using namespace std;
vector<vector<pair<int, int>>> g;
bool change(pair<int, int> &a, pair<int, int> b){
    bool changed=(a.f<b.f) or (a.s>b.s);
    a.f = max(a.f, b.f);
    a.s = min(a.s, b.s);
    return changed;
}
int main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    vector<pair<pair<int, int>, pair<int, int>>> edges;
    cin >> n >> m;
    g.assign(n, {});
    vector<vector<pair<int, int>>> dist(n, vector<pair<int, int>>(n, {-800, 800}));
    vector<vector<int>> dist2(n, vector<int>(n, -1));
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;b--;
        dist2[a][b]=1;
        dist2[b][a]=1;
        if(c == 0){
            edges.push_back({{a, b}, {-1, 1}});
            edges.push_back({{b, a}, {-1, 1}});
        }else{
            edges.push_back({{a, b}, {1, 1}});
            edges.push_back({{b, a}, {-1, -1}});
        }
        //if(c == 0){
        //    g[a].push_back({b, 0});
        //    g[b].push_back({a, 0});
        //}else{
        //    g[a].push_back({b, 1});
        //    g[b].push_back({a, -1});
        //}
    }
    for (int i = 0; i < n; ++i) {
        dist[i][i] = {0, 0};
        dist2[i][i]=0;
    }
    vector<int> isEven(n,-1);
    isEven[0]=0;
    int checker=n+2;
    bool BadUser=false;
    while(checker>0 and !BadUser){
        for(auto edge: edges){
            int a = edge.f.f, b = edge.f.s;
            BadUser=BadUser or ((isEven[a]==isEven[b]) and(isEven[a]>-1));
            if(isEven[a]>-1)
                isEven[b]=(isEven[a]+1)%2;
        }
        checker--;
    }
    bool isChanged= true;
    while (isChanged && !BadUser ) {
        isChanged=false;
        for (auto edge : edges) {
            int a = edge.f.f, b = edge.f.s;
            if(dist[a][b].f==dist[a][b].s && dist[a][b].f==0)
                BadUser=true;
            for (int c = 0; c < n && !BadUser ; ++c) {
                bool cc=change(dist[c][b], {dist[c][a].f + edge.s.f, dist[c][a].s + edge.s.s});
                isChanged =isChanged or cc;
                BadUser=BadUser or (dist[c][b].f > dist[c][b].s);
            }
        }
    }
    int ans=0;
    int ii=0;
    int jj=0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(dist[i][j].s<300){
                if(ans<dist[i][j].s){
                    ans=dist[i][j].s;
                    ii=i;
                    jj=j;
                }
            }
        }
    }
    dist[ii][jj].f=ans;
    bool theEnd=false;
    bool isFirst= false;
    while(!theEnd){
        theEnd=isFirst;
        for(int i=0;i<n && theEnd;i++){
            if(dist[ii][i].f!=dist[ii][i].s){
                theEnd=false;
                dist[ii][i].f=dist[ii][i].s;
            }
        }
        if(!theEnd){
            isChanged= true;
            while (isChanged and !BadUser ) {
                isChanged=false;
                for (auto edge : edges) {
                    int a = edge.f.f, b = edge.f.s;
                    if(dist[a][b].f==dist[a][b].s && dist[a][b].f==0)
                        BadUser=true;
                    for (int c = 0; c < n; ++c) {
                        bool cc=change(dist[c][b], {dist[c][a].f + edge.s.f, dist[c][a].s + edge.s.s});
                        isChanged =isChanged or cc;
                        BadUser=BadUser or (dist[c][b].f > dist[c][b].s);
                    }
                }
            }

        }
        theEnd=theEnd || BadUser;
        isFirst=true;
    }
    if(BadUser){
        cout<<"NO\n"<<endl;
        return 0;
    }

    cout<<"YES\n"<<ans<<endl;
    for(int i=0;i<n;i++)
        cout<<dist[ii][i].f<<" ";
    cout<<endl;
    return 0;
}