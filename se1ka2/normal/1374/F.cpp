#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef pair<int, int> P;

void rotate(int i, map<P, int> &mp, P *p){
    P t = p[i];
    p[i] = p[i - 1];
    mp[p[i]] = i;
    p[i - 1] = p[i - 2];
    mp[p[i - 1]] = i - 1;
    p[i - 2] = t;
    mp[p[i - 2]] = i - 2;
}

void act(int i, map<P, int> &mp, P *p, vector<int> &ans, int n){
    auto itr = mp.begin();
    int k = itr->second;
    if((k - i) % 2){
        if(k != n - 1){
            rotate(k + 1, mp, p);
            ans.push_back(k - 1);
            rotate(k + 1, mp, p);
            ans.push_back(k - 1);
        }
        else{
            rotate(k, mp, p);
            ans.push_back(k - 2);
            rotate(k, mp, p);
            ans.push_back(k - 2);
        }
        k--;
    }
    for(; k > i; k -= 2){
        rotate(k, mp, p);
        ans.push_back(k - 2);
    }
    mp.erase(itr->first);
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        map<int, int> cnt;
        map<P, int> mp;
        P p[502];
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            p[i] = P(a, cnt[a]);
            mp[p[i]] = i;
            cnt[a]++;
        }
        vector<int> ans;
        for(int i = 0; i < n - 2; i++) act(i, mp, p, ans, n);
        bool f = true;
        if(p[n - 2].first > p[n - 1].first){
            f = false;
            if(p[n - 1].first == p[n - 3].first){
                f = true;
                rotate(n - 1, mp, p);
                ans.push_back(n - 3);
            }
            else{
                for(int i = 0; i < n - 1; i++){
                    if(p[i].first == p[i + 1].first){
                        rotate(i + 2, mp, p);
                        ans.push_back(i);
                        rotate(i + 2, mp, p);
                        ans.push_back(i);
                        mp.erase(p[i]);
                        for(int j = i + 1; j < n - 2; j++) act(j, mp, p, ans, n);
                        f = true;
                        break;
                    }
                }
            }
        }
        if(!f) cout << -1 << endl;
        else{
            cout << (int)ans.size() << endl;
            for(int i : ans) cout << i + 1 << " ";
            cout << endl;
        }
    }
}