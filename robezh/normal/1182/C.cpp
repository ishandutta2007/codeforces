#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
typedef long long ll;
const int N = (int)1e5 + 50, M = (int)1e6 + 50;

struct ss {
    int la, id;
};

string vo = "aeiou";
int n;
map<char, int> mp;
vector<ss> gp[M];
int rem[M];
bool good[N];
string str[N];
int la[N], cnt[N];
vector<int> res;

int main() {
    for(int i = 0; i < vo.size(); i++) mp[vo[i]] = i;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> str[i];
        for(char c : str[i]) {
            if(mp.find(c) != mp.end()) {
                cnt[i]++;
                la[i] = mp[c];
            }
        }
        gp[cnt[i]].push_back({la[i], i});
        rem[cnt[i]] ++;
    }
    vector<int> yet;
    for(int i = 0; i < M; i++) {
        sort(gp[i].begin(), gp[i].end(), [](const ss &s1, const ss &s2) {
            return s1.la < s2.la;
        });
        for(int j = 0; j + 1 < gp[i].size(); j++) {
            if(gp[i][j].la == gp[i][j+1].la) {
                res.push_back(gp[i][j].id);
                res.push_back(gp[i][j+1].id);
                good[gp[i][j].id] = good[gp[i][j+1].id] = true;
                j++;
            }
        }
        int id = -1;
        for(ss &s : gp[i]) {
            if(!good[s.id]) {
                if(id == -1) id = s.id;
                else {
                    yet.push_back(id);
                    yet.push_back(s.id);
                    id = -1;
                }
            }
        }
    }
    while(res.size() > yet.size()) {
        yet.push_back(res.back());
        res.pop_back();
        yet.push_back(res.back());
        res.pop_back();
    }
    cout << res.size() / 2 << endl;
    for(int i = 0; i < res.size(); i += 2) {
        cout << str[yet[i]] << " " << str[res[i]] << "\n";
        cout << str[yet[i+1]] << " " << str[res[i+1]] << "\n";
    }





}