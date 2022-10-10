#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    unordered_set<string> polandVocab, enemyVocab;
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        polandVocab.insert(s);
    }
    for (int i=0; i<m; i++) {
        string s;
        cin >> s;
        enemyVocab.insert(s);
    }
    
    bool polandTurn = true;
    while (true) {
        if (polandTurn) {
            if (polandVocab.size() == 0) {
                cout << "NO" << endl;
                return 0;
            }
            bool shareVocab = false;
            for (string s : polandVocab)
                if (enemyVocab.find(s) != enemyVocab.end()) {
                    shareVocab = true;
                    polandVocab.erase(s);
                    enemyVocab.erase(s);
                    break;
                }
            if (!shareVocab)
                polandVocab.erase(polandVocab.begin());
            polandTurn = false;
        } else {
            if (enemyVocab.size() == 0) {
                cout << "YES" << endl;
                return 0;
            }
            bool shareVocab = false;
            for (string s : enemyVocab)
                if (polandVocab.find(s) != polandVocab.end()) {
                    shareVocab = true;
                    polandVocab.erase(s);
                    enemyVocab.erase(s);
                    break;
                }
            if (!shareVocab)
                enemyVocab.erase(enemyVocab.begin());
            polandTurn = true;
        }
    }
    
    return 0;
}