#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <set>
#include <hash_map>
#include <functional>
#include <sstream>
using namespace std;

const double eps = 1e-5;

struct envelope {
    int W;
    int H;
    int N;

    envelope() : W(0), H(0), N(0) {}
};

bool operator< (const envelope& e1, const envelope& e2)
{
    return e1.W < e2.W;
}

int main()
{
    int n = 0;
    int w = 0, h = 0;
    cin >> n >> w >> h;
    vector<envelope> envelopes;
    for (int i = 0; i < n; i++) {
        envelope env;
        cin >> env.W >> env.H;
        if (env.W <= w || env.H <= h) {
            continue;
        }
        env.N = i + 1;
        envelopes.push_back(env);
    }
    if (envelopes.size() == 0) {
        cout << 0;
        return 0;
    }
    sort(envelopes.begin(), envelopes.end());
    vector<int> d(envelopes.size(), 1);
    vector<int> p(envelopes.size(), -1);
    d[0] = 1;
    for (int i = 1; i < envelopes.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (envelopes[j].W == envelopes[i].W) {
                break;
            }
            if (envelopes[j].H < envelopes[i].H && d[j] + 1 > d[i]) {
                d[i] = d[j] + 1;
                p[i] = j;
            }
        }
    }
    int max_chain = 0;
    int max_chain_index = -1;
    for (int i = 0; i < envelopes.size(); i++) {
        if (d[i] > max_chain) {
            max_chain = d[i];
            max_chain_index = i;
        }
    }
    cout << max_chain << endl;
    vector<int> chain;
    while (max_chain_index != -1) {
        chain.push_back(envelopes[max_chain_index].N);
        max_chain_index = p[max_chain_index];
    }
    for (int i = chain.size() - 1; i >= 0; --i) {
        cout << chain[i] << " ";
    }
    cout<<endl; //sdfssd
    return 0;
}