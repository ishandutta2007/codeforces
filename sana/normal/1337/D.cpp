#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

long long calc(int a, int b, int c) {
    long long dab = a-b;
    long long dbc = b-c;
    long long dac = a-c;
    return dab*dab+dbc*dbc+dac*dac;
}

long long getAnswer(const vector<int>& r, const vector<int>& g, const vector<int>& b, long long bestAnswer) {
    int nr = r.size(), ng = g.size(), nb = b.size();

    for (int i = 0; i < nr; i++) {
        int fg = lower_bound(g.begin(),g.end(),r[i]) - g.begin();
        int fb = lower_bound(b.begin(),b.end(),r[i]) - b.begin();

        if (fg == ng || fb == nb) break;

        if (g[fg] <= b[fb]) {
            int ffg = lower_bound(g.begin(),g.end(),(r[i]+b[fb])/2) - g.begin();

            long long thisAnswer;
            
            if (ffg < ng) {
                thisAnswer = calc(r[i], g[ffg], b[fb]);
                if (bestAnswer == -1 || thisAnswer < bestAnswer) bestAnswer = thisAnswer;
            }

            if (ffg > 0) {
                thisAnswer = calc(r[i], g[ffg-1], b[fb]);
                if (bestAnswer == -1 || thisAnswer < bestAnswer) bestAnswer = thisAnswer;
            }
        }
        else {
            int ffb = lower_bound(b.begin(),b.end(),(r[i]+g[fg])/2) - b.begin();

            long long thisAnswer;
            
            if (ffb < nb) {
                thisAnswer = calc(r[i], g[fg], b[ffb]);
                if (bestAnswer == -1 || thisAnswer < bestAnswer) bestAnswer = thisAnswer;
            }

            if (ffb > 0) {
                thisAnswer = calc(r[i], g[fg], b[ffb-1]);
                if (bestAnswer == -1 || thisAnswer < bestAnswer) bestAnswer = thisAnswer;
            }
        }
    }

    return bestAnswer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t; cin >> t;
    for (int testcase = 0; testcase < t; testcase++) {
        long long bestAnswer = -1;
        int nr, ng, nb; cin >> nr >> ng >> nb;
        vector<int> r(nr), g(ng), b(nb);
        for (int i = 0; i < nr; i++) cin >> r[i];
        for (int i = 0; i < ng; i++) cin >> g[i];
        for (int i = 0; i < nb; i++) cin >> b[i];

        sort(r.begin(),r.end());
        sort(g.begin(),g.end());
        sort(b.begin(), b.end());
        
        bestAnswer = getAnswer(r,g,b,bestAnswer);
        bestAnswer = getAnswer(g,r,b,bestAnswer);
        bestAnswer = getAnswer(b,r,g,bestAnswer);

        cout << bestAnswer << '\n';
        
    }

    return 0;
}