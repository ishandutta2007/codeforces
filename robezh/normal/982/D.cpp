#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
const int N = (int)1e5 + 500;
const int INF = (int)2e9;

int n;
int ans[N], num[N];
P p[N];
map<int, int> mp;
multiset<int> cnts;

int main() {
    fill(ans, ans+N, INF);

    scanf("%d", &n);
    mp[0] = n-1; cnts.insert(n);
    for(int i = 0; i < n; i++) scanf("%d", &p[i].first), p[i].second = i;
    sort(p, p+n, greater<P>());
    ans[1] = p[0].first + 1;
    for(int i = 0; i < n; i++){
        int ind = p[i].second;
        auto it = mp.upper_bound(ind);
        it--;
        int fir = it -> first, sec = it -> second;
        mp.erase(it), cnts.erase(cnts.find(sec-fir+1));
        if(fir == sec && fir == ind){}
        else if(ind == fir){
            mp[ind+1] = sec;
            cnts.insert(sec-ind);
        }
        else if(ind == sec){
            mp[fir] = sec-1;
            cnts.insert(sec-fir);
        }
        else{
            //cout << fir << " " << sec << " " << ind << endl;
            mp[fir] = ind-1;
            mp[ind+1] = sec;
            cnts.insert(ind-fir);
            cnts.insert(sec-ind);
        }
//        for(int x : cnts) cout << x << " ";
//        cout << endl;

        if(!cnts.empty() && *(cnts.begin()) == *(--cnts.end())){
            //cout << cnts.size() << ": element is " << *cnts.end() << " ,k now is " << p[i].first << endl;
            ans[cnts.size()] = min(ans[cnts.size()], p[i+1].first + 1);
        }
    }
    int res = 0;
    for(int i = n; i >= 0; i--){
        if(ans[i] != INF){
            //cout << "divided in " << i << ", while k = " << ans[i] << endl;
            res = ans[i];
            break;
        }
    }
    cout << res;

}