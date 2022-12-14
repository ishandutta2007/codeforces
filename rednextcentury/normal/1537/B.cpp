#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios_base::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
        int n,m,x,y;
        cin>>n>>m>>x>>y;
        ll ret=-1;
        vector<pair<ll,ll> > pos = {{1,1}, {1, m}, {n, m}, {n, 1}};
        pair<int,int> A,B;
        for (auto p:pos) {
            for (auto q:pos) {
                ll cur = abs(p.first-x)+abs(p.second-y)+abs(q.first-x)+abs(q.second-y)+abs(p.first-q.first)+abs(p.second-q.second);
                if (cur>ret)
                    A = p, B=q, ret=cur;
            }
        }
        cout<<A.first<<' '<<A.second<<' '<<B.first<<' '<<B.second<<endl;
    }
}