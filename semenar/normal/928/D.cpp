#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream fin("input.txt");

    string s = "";
    while (!cin.eof()) {
        string line;
        getline(cin, line);
        if (line.size() > 0) {
            line.push_back('#');
            s.append(line);
        }
        else break;
    }

    vector<string> words;
    string cur_str = "";
    for (auto ch : s) {
        if (ch >= 'a' && ch <= 'z') cur_str.push_back(ch);
        else {
            if (cur_str.size() > 0) words.push_back(cur_str);
            cur_str = "";
        }
    }

    int ans = (int)s.size();
    for (auto word : words) ans -= (int)word.size();

    vector<unordered_map<char, pair<int, bool>>> gr(1);
    vector<bool> dat(1);

    for (auto word : words) {
        int furthest_suggest = 0;
        int furthest_complete = 0;
        int pos = 0;
        vector<pair<int, char>> punishable;
        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];
            if (dat[pos]) furthest_complete = i;
            if (gr[pos].count(ch) != 0) {
                if (gr[pos][ch].second && furthest_suggest == 0) furthest_suggest = i + 1;
                punishable.push_back(make_pair(pos, ch));
                pos = gr[pos][ch].first;
            }
            else {
                gr[pos][ch] = make_pair((int)gr.size(), true);
                pos = gr.size();
                gr.emplace_back();
                dat.push_back(false);
            }
        }

        if (dat[pos]) furthest_complete = word.size();
        else {
            for (auto elem : punishable) gr[elem.first][elem.second].second = false;
        }
        dat[pos] = true;

        if (furthest_suggest == 0 || furthest_complete == 0 || furthest_suggest >= furthest_complete) {
            ans += word.size();
        }
        else {
            ans += (int)word.size() + furthest_suggest - furthest_complete + 1;
        }
    }

    cout << ans << endl;

    return 0;
}