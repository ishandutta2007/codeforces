#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;

int n;
int num[5005];
map<int, int> mp[5005];
int psum[5005];

int getsum(int i, int j){
    return psum[j] - psum[i-1];
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> num[i];
    psum[0] = 0;
    for(int i = 1; i <= n; i++) psum[i] = psum[i-1] + num[i];

    mp[0][0] = 0;
    int res = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < i; j++){
            int now = getsum(j+1, i);
            auto it = mp[j].upper_bound(now);
            if(it == mp[j].begin()) continue;
            it--;
            //if(it == mp[j].end()) continue;
            int newlen = it -> second + 1;

            it = mp[i].upper_bound(now);
            if(it != mp[i].begin()){
                it--;
                if(it -> second >= newlen) continue;
            }

            it = mp[i].upper_bound(now);
            while(it != mp[i].end() && it -> second <= newlen){
                it = mp[i].erase(it);
            }
            mp[i][now] = newlen;
            res = max(res, newlen);

        }
    }
//    for(int i = 0; i <= n; i++){
//        cout << "i : " << i << endl;
//        for(P p : mp[i]){
//            cout << p.first << " " << p.second << endl;
//        }
//    }

    cout << n - res << endl;
}