#include <bits/stdc++.h>
using namespace std;

struct two_sat {
    int N;
    vector<vector<int>> impl;
    vector<int> visit, label, comp, added;
    vector<bool> in_view;

    two_sat(int _N) {
        N = _N;
        impl.resize(2 * N);
        added.resize(2 * N);
        visit.resize(2 * N);
        label.resize(2 * N);
        comp.resize(2 * N);
        in_view.resize(2 * N);
    }

    void begin() {
        fill(added.begin(), added.end(), 0);
    }

    void end() {
        for (int i = 0; i < 2 * N; i++) {
            for (int j = 0; j < added[i]; j++) 
                impl[i].pop_back();
            added[i] = 0;
        }
    }

    void add_impl(int var1, bool neg1, int var2, bool neg2) {
        impl[2 * var1 + neg1].push_back(2 * var2 + neg2);
        added[2 * var1 + neg1]++;
        impl[2 * var2 + !neg2].push_back(2 * var1 + !neg1);
        added[2 * var2 + !neg2]++;
    }

    void add_clause(int var1, bool neg1, int var2, bool neg2) {
        add_impl(var1, !neg1, var2, neg2);
    }

    void add_clause(int var1, bool neg1) {
        add_clause(var1, neg1, var1, neg1);
    }

    int V, L, C;
    stack<int> view;

    int dfs(int loc) {
        visit[loc] = V;
        label[loc] = L++;

        int low = label[loc];
        view.push(loc);
        in_view[loc] = true;

        for (int nbr : impl[loc]) {
            if(!visit[nbr]) low = min(low, dfs(nbr));
            else if(in_view[nbr]) low = min(low, label[nbr]);
        }

        if(low == label[loc]) {
            while (true) {
                int mem = view.top();
                comp[mem] = C;
                in_view[mem] = false;
                view.pop();
                if(mem == loc) break;
            }
            C++;
        }

        return low;
    }

    bool consistent() {
        V = 0, L = 0, C = 0;

        fill(visit.begin(), visit.end(), 0);
        fill(in_view.begin(), in_view.end(), 0);
        fill(label.begin(), label.end(), 0);
        fill(comp.begin(), comp.end(), 0);
        
        for (int i = 0; i < 2 * N; i++) {
            if(!visit[i]) {
                V++;
                dfs(i);
            }
        }

        for (int i = 0; i < N; i++)
            if(comp[2 * i] == comp[2 * i + 1]) {
                return false;
            }

        return true;
    }
};

const int MAXN = 256;
const int MAXM = 4 * MAXN * MAXN;

string alphabet;
int A, cons;
bool type[30];

int N, M;
int var1[MAXM], var2[MAXM];
bool neg1[MAXM], neg2[MAXM];

unordered_map<string, bool> cache;

bool make(two_sat &ts, string arg) {
    for (int i = 0; i < N; i++) {
        if(arg[i] != '?')
            arg[i] = type[arg[i] - 'a'] ? 'C' : 'V';
        else {
            if(cons == 0) arg[i] = 'V';
            if(cons == A) arg[i] = 'C';
        }
    }
    if(cache.count(arg)) return cache[arg];

    ts.begin();

    for (int i = 0; i < N; i++) {
        if(arg[i] == '?') continue;
        if(arg[i] == 'C') {
            ts.add_impl(i, false, i, true);
        }
        else {
            ts.add_impl(i, true, i, false);
        }
    }

    bool res = ts.consistent();
    ts.end();
    cache[arg] = res;
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> alphabet;
    A = alphabet.size();

    for (int i = 0; i < A; i++) {
        type[i] = alphabet[i] == 'C';
        cons += int(alphabet[i] == 'C');
    }

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        char v1, v2;
        cin >> var1[i] >> v1 >> var2[i] >> v2;

        var1[i]--, var2[i]--;
        neg1[i] = (v1 == 'C'), neg2[i] = (v2 == 'C');
    }

    two_sat ts(N);

    for (int i = 0; i < M; i++) {
        ts.add_impl(var1[i], neg1[i], var2[i], neg2[i]);
    }

    string input;
    cin >> input;

    if(make(ts, input)) {
        cout << input << endl;
        return 0;
    }

    char LIM = 'a' + A;

    for (int i = N-1; i >= 0; i--) {

        while(++input[i] < LIM) {
            if(make(ts, input)) {
                for (int j = i+1; j < N; j++) {
                    for (input[j] = 'a'; input[j] < LIM; input[j]++)
                        if(make(ts, input)) break;
                } 

                cout << input << endl;
                return 0;
            }
        }

        input[i] = '?';
    }

    cout << -1 << endl;
}