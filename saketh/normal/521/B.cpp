#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

int M;
int X[100005], Y[100005];
map<pair<int, int>, int> look;

vector<pair<pair<int, int>, int> > srt;
set<pair<int, int> > all;
set<int> rem;

int num_supp(int y, int x){
    return all.count(make_pair(y-1, x-1))
         + all.count(make_pair(y-1, x))
         + all.count(make_pair(y-1, x+1));
}

bool can_rem(int y, int x){
    if(!all.count(make_pair(y, x))) return false;
    for(int xx=x-1; xx<=x+1; xx++)
        if(all.count(make_pair(y+1, xx)))
            if(num_supp(y+1, xx) == 1)
                return false;
    return true;
}

void proc_del(int val){
    int x = X[val], y = Y[val];

    for(int xx=x-1; xx<=x+1; xx++)
        if(can_rem(y-1, xx)){
            int that = look[make_pair(y-1, xx)];
            rem.insert(that);
        }

    for(int xx=x-2; xx<=x+2; xx++)
        if(all.count(make_pair(y, xx))){
            if(!can_rem(y, xx)){
                int that = look[make_pair(y, xx)];
                rem.erase(that);
            }
        }
}

int main(){
    cin >> M;
    for(int i=0; i<M; i++){
        cin >> X[i] >> Y[i];
        look[make_pair(Y[i], X[i])] = i;
        all.insert(make_pair(Y[i], X[i]));
        srt.emplace_back(make_pair(Y[i], X[i]), i);    
    }

    sort(srt.begin(), srt.end());

    for(int i=M-1; i>=0; i--){
        if(can_rem(srt[i].first.first, srt[i].first.second))
            rem.insert(srt[i].second);
    }

    long long res = 0;
    bool big = true;

    while(all.size()){
        int val;

        if(big){
            val = *rem.rbegin();
        }
        else{
            val = *rem.begin();
        }

        res = (res * M + val) % 1000000009;
        rem.erase(val);
        all.erase(make_pair(Y[val], X[val]));
        proc_del(val);
        big = !big;    
    }

    cout << res << endl;
}