#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cassert>
using namespace std;
int cnt[256];
typedef long long li;
void solve();
int main(){

    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}

int n, m;
struct segment{
    int from,to;

    segment(int a, int b){
        from = a;
        to = b;
    }

    int maxL() const {
        if(from == 1)
            return to;
        if(to == n)
            return n - from + 1;

        int len = to - from + 1;


        return (len + 1)/2;
    }

    bool operator < (const segment& b) const{
        if(maxL() != b.maxL())
            return maxL() > b.maxL();

        return from < b.from;
    }

};

set<segment> s;
set<int> used;
int wher[1010101];
void solve(){
    
    //freopen("input.txt", "r", stdin);
    cin>>n>>m;
    s.insert(segment(1, n));

    for(int i = 0; i < m ;++i){
        //cerr<<"i = "<<i<<endl;
        //cerr<<"-----------------\n";
        int type, id;
        cin>>type>>id;
        if(type - 1){
            int w = wher[id];
            used.erase(w);
            //cerr<<"erase "<<w<<endl;
            set<int>::iterator it = used.lower_bound(w);
            int from, to;
            if(it == used.end()){
                s.erase(segment( w + 1, n));
                to = n;
            }
            else{
                s.erase(segment(w + 1, *it - 1));
                to = * it - 1; 
            }

            if(it == used.begin()){
                s.erase(segment(1, w - 1));
                from = 1;
            }
            else{
                --it;
                s.erase(segment(*it + 1, w - 1));
                from = * it + 1;
            }
            s.insert(segment(from, to));
            
        }
        else{
            assert(s.begin()!= s.end());
            segment best = *s.begin();
            s.erase(s.begin());

            int w = best.from - 1 + best.maxL();
            if(best.to == n)
                w = n;
            if(best.from == 1)
                w = 1;

            wher[id] = w;
            cout<<w<<'\n';


            if(best.from <= w - 1)
                s.insert(segment(best.from, w- 1));
            if(w + 1 <= best.to)
                s.insert(segment(w + 1, best.to));

            used.insert(w);
        }

        
        //for(set<segment>::iterator it = s.begin();  it!= s.end(); ++it){
    //      cerr<<it->from<<' '<<it->to<<endl;
        //}
    }


}