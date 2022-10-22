#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> s;

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        s.push_back(make_pair(i + 1, t));
    }
    while(s.size() > 1){
        pair<int, int> t = s[0];
        s.erase(s.begin() + 0);
        t.second -= m;
        if(t.second > 0)
            s.push_back(t);
    }
    cout << s[0].first << endl;
    return 0;
}