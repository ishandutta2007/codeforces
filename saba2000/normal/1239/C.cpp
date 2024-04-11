#include<bits/stdc++.h>
#define int long long
using namespace std;
deque<int> q;
set<pair<int,int> > ev;
int emp = 1,p;
int ans[200009];
void rem(int x, int T){
    ans[x] = T;
    emp = 1;
    q.pop_front();
    if(q.size()) {
        ev.insert({ T+ p,-q.front()});
        emp = 0;
    }

}
main(){
    int n;
    cin >> n >> p;
    for(int i= 1; i <= n;i++){
        int t;
        cin >> t;
        ev.insert({t, i});
    }
    set<int> gt, wt;
    while(ev.size()){
        auto t = *(ev.begin());
        ev.erase(ev.begin());
        if(t.second < 0) rem(-t.second, t.first);
        else wt.insert(t.second);
        while(ev.size() && ev.begin()->first == t.first){
            auto r = *(ev.begin());
            ev.erase(ev.begin());
            wt.insert(r.second);
        }
        while(wt.size() && (q.size() == 0 || (*(wt.begin())) < q.back())){
            int A = *(wt.begin());
            wt.erase(wt.begin());
            q.push_back(A);
            if(q.size()==1) {
                ev.insert( {t.first + p, -A});
                emp = 0;

            }
        }

    }
    for(int i = 1; i <= n; i++)
        cout<<ans[i]<<" ";
    cout<<endl;

}
/*

[       ]x
*/