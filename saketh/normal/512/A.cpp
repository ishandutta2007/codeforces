#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N;
string name[128];

vector<int> succ[26];
int ind[26];

void proc(int i, int j) {
    int A = name[i].size(), B = name[j].size();

    if (A > B && name[i].substr(0, B) == name[j]) {
        cout << "Impossible\n";
        exit(0);
    }

    if (A <= B && name[j].substr(0, A) == name[i]) return;

    int d = 0;
    while(name[i][d] == name[j][d]) d++;

    succ[name[i][d]-'a'].push_back(name[j][d]-'a');
    ind[name[j][d]-'a']++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> name[i];

    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            proc(i, j);

    vector<char> ans;
    queue<int> q;

    for (int i = 0; i < 26; i++)
        if(ind[i] == 0)
            q.push(i);

    while(!q.empty()) {
        int val = q.front();
        q.pop();

        ans.push_back(val + 'a');

        for (int nbr : succ[val]) 
            if(--ind[nbr] == 0)
                q.push(nbr);
    }

    if (ans.size() == 26) {
        for (char c : ans) cout << c;
        cout << endl;
    }
    else cout << "Impossible\n";
}