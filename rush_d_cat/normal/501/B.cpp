#include <map>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
int n;
map<string, string> mp, par;
vector<string> vec;
map<string, int> vis;

int main() {
    cin >> n;
    string s1, s2;
    for(int i=1;i<=n;i++) {
        cin >> s1 >> s2;

        if(vis[s1] != 1) {
            vec.push_back(s1);
            par[s1] = s1;
        }

        par[s2] = par[s1];
        mp[par[s1]] = s2;

        vis[s1] = 1, vis[s2] = 1;
    }

    cout << vec.size() << endl;
    for(int i=0;i<vec.size();i++) {
        cout << vec[i] << " " << mp[vec[i]] << endl;
    }
}