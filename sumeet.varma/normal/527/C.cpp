#include <bits/stdc++.h>

#define sl ios::sync_with_stdio(0); cin.tie(0);
#define ll long long;

using namespace std;

int main(){ sl
    int w,h,n;
    cin >> w >> h >> n;

    set<int> hset ;
    hset.insert(0);
    hset.insert(h);

    set<int> wset ;
    wset.insert(0);
    wset.insert(w);

    map<int,int> hdiff;
    hdiff.insert(make_pair(h,1));

    map<int,int> wdiff;
    wdiff.insert(make_pair(w,1));

    for(int i=0;i<n;i++){
        char type;
        cin >> type;
        int d;
        cin >> d;

        if(type == 'H'){
            hset.insert(d);

            set<int>::iterator it = hset.find(d);
            it++;
            int r = *it;
            it--;
            it--;
            int l = *it;

            hdiff[r-l]--;
            if(hdiff[r-l] == 0)
                hdiff.erase(hdiff.find(r-l));
            if(hdiff.find(d-l) == hdiff.end())
                hdiff.insert(make_pair(d-l,1));
            else
                hdiff[d-l]++;
            if(hdiff.find(r-d) == hdiff.end())
                hdiff.insert(make_pair(r-d,1));
            else
                hdiff[r-d]++;

        }

        else{
            wset.insert(d);

            set<int>::iterator it = wset.find(d);
            it++;
            int r = *it;
            it--;
            it--;
            int l = *it;

            wdiff[r-l]--;
            if(wdiff[r-l] == 0)
                wdiff.erase(wdiff.find(r-l));
            if(wdiff.find(d-l) == wdiff.end())
                wdiff.insert(make_pair(d-l,1));
            else
                wdiff[d-l]++;
            if(wdiff.find(r-d) == wdiff.end())
                wdiff.insert(make_pair(r-d,1));
            else
                wdiff[r-d]++;
        }

        cout << ((--hdiff.end())->first) * 1LL * ((--wdiff.end())->first) << endl;
    }

    return 0 ;
}