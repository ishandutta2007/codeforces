
#include <bits/stdc++.h>
using namespace std;

struct oper{long long i, j, d;};

int main(){
    long long n;
    cin >> n;
    vector<long long> pos(n + 1), t(n);
    for (long long i = 0; i < n; ++i) cin >> pos[i];
    for (long long i = 0; i < n; ++i) cin >> t[i];
    sort(t.begin(), t.end());
    vector<oper> moves;
    auto comp = [&](long long i, long long j){return pos[i] < pos[j] || (pos[i] == pos[j] && i > j);};
    set<long long, decltype(comp)> todo(comp);
    for (long long i = 0; i < n; ++i) todo.insert(i);
    while (!todo.empty()){
        long long i = *(--todo.end());
        todo.erase(--todo.end());
        long long goal = pos[n] = t[todo.size()];
        if (pos[i] < goal){
            cout << "NO" << endl;
            return 0;
        }
        while (pos[i] > goal){
            auto it = todo.lower_bound(n);
            if (it == todo.begin()){
                cout << "NO" << endl;
                return 0;
            }
            --it;
            long long j = *it;
            todo.erase(it);
            long long d = min(pos[i] - goal, (pos[i] - pos[j]) / 2);
            moves.push_back({j, i, d});
            pos[i] -= d;
            pos[j] += d;
            todo.insert(j);
        }
    }
    cout << "YES" << endl;
    cout << moves.size() << endl;
    for (oper o : moves) cout << o.i + 1 << ' ' << o.j + 1 << ' ' << o.d << endl;
    return 0;
}