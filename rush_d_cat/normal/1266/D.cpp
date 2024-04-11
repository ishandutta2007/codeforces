#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
using namespace std;
const int N=300000+10;
typedef long long LL;
int n,m;
LL s[N];
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v,d; scanf("%d%d%d",&u,&v,&d);
        s[u]+=d, s[v]-=d;
    }
    set< pair<LL,int> > st1,st2;
    for(int i=1;i<=n;i++){
        if(s[i]>0) st1.insert(make_pair(s[i],i));
        if(s[i]<0) st2.insert(make_pair(s[i],i));
    }

    vector< pair<pair<int,int>, LL> > ans;
    while(st1.size()){
        {
            pair<LL,int> p1 = *st1.rbegin();
            pair<LL,int> p2 = *st2.rbegin();
            //printf("(%lld,%d) (%lld,%d)\n", p1.first,p1.second,p2.first,p2.second);
            if (p1.first + p2.first >= 0) {
                st1.erase(p1); st2.erase(p2);
                ans.push_back( make_pair(make_pair(p1.second, p2.second), -p2.first) );
                p1.first += p2.first;
                if (p1.first > 0) st1.insert(p1);
                continue;
            }
        }

        {
            pair<LL,int> p1 = *st1.begin();
            pair<LL,int> p2 = *st2.begin();
            //printf("(%lld,%d) (%lld,%d)\n", p1.first,p1.second,p2.first,p2.second);
            if (p1.first + p2.first <= 0) {
                st1.erase(p1); st2.erase(p2);
                ans.push_back( make_pair(make_pair(p1.second, p2.second), p1.first) );
                p2.first += p1.first;
                if (p2.first < 0) st2.insert(p2);
                continue;
            }
        }
    }
    printf("%d\n", ans.size());
    for (auto p: ans) {
        printf("%d %d %lld\n", p.first.first,p.first.second,p.second);
    }
}