#include <string>
#include <string.h>
#include <map>
#include <set>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef long long li;
typedef pair<li, li> pli;
typedef long double ld;
void solve();

int main(){
#ifdef DEBUG
    freopen("input", "r", stdin);
#endif
    solve();
    return 0;
}
void solve(){
    int n;
    cin>>n;
    map<pi,int> res;
    queue<pi> q;
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    pi from(a,b),to(c,d);
    q.push(from);
    res[from]=0;
    while(res.find(to)==res.end()){
        pi t=q.front();
        q.pop();
        int wr=res[t]+1;
        if(t.second==n || t.second==0){
            if(t.first!=n){
                pi next(t.first+1,t.second);
                if(res.find(next)==res.end()){
                    q.push(next);
                    res[next]=wr;
                }
            }
            if(t.first!=0){
                pi next(t.first-1,t.second);
                if(res.find(next)==res.end()){
                    q.push(next);
                    res[next]=wr;
                }
            }
        }
        if(t.first==n || t.first==0){
            if(t.second!=n){
                pi next(t.first,t.second+1);
                if(res.find(next)==res.end()){
                    q.push(next);
                    res[next]=wr;
                }
            }
            if(t.second!=0){
                pi next(t.first,t.second-1);
                if(res.find(next)==res.end()){
                    q.push(next);
                    res[next]=wr;
                }
            }
        }
    }
    cout<<res[to];
}