#include <bits/stdc++.h>
using namespace std;

struct Pred {
    int taken, group;
};

string table[] = {"","H","He","Li","Be","B","C","N","O","F","Ne","Na","Mg","Al","Si","P","S","Cl",
                "Ar","K","Ca","Sc","Ti","V","Cr","Mn","Fe","Co","Ni","Cu","Zn","Ga","Ge","As","Se",
                "Br","Kr","Rb","Sr","Y","Zr","Nb","Mo","Tc","Ru","Rh","Pd","Ag","Cd","In","Sn","Sb",
                "Te","I","Xe","Cs","Ba","La","Ce","Pr","Nd","Pm","Sm","Eu","Gd","Tb","Dy","Ho","Er",
                "Tm","Yb","Lu","Hf","Ta","W","Re","Os","Ir","Pt","Au","Hg","Tl","Pb","Bi","Po","At",
                "Rn","Fr","Ra","Ac","Th","Pa","U","Np","Pu","Am","Cm","Bk","Cf","Es","Fm","Md","No",
                "Lr"};
unordered_map<string, int> mp;

int atoms[17], goal[17], pre[1<<17] = {};
bool dp[18][1<<17] = {};
Pred pred[18][1<<17];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    for (int i=1; i<=100; i++)
        mp[table[i]] = i;

    int n, k;
    cin >> n >> k;
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        atoms[i] = mp[s];
    }
    for (int i=0; i<k; i++) {
        string s;
        cin >> s;
        goal[i] = mp[s];
    }

    for (int mask=0; mask<1<<n; mask++)
        for (int i=0; i<n; i++)
            if (mask & (1 << i))
                pre[mask] += atoms[i];

    dp[0][0] = true;
    for (int i=1; i<=k; i++)
        for (int mask=0; mask<1<<n; mask++)
            if (dp[i-1][mask]) {
                int notTaken = ~mask & ((1 << n) - 1);
                for (int s=notTaken; s>0; s=(s-1)&notTaken)
                    if (pre[s] == goal[i-1]) {
                        dp[i][mask | s] = true;
                        pred[i][mask | s] = {mask, s};
                    }
            }

    for (int mask=0; mask<1<<n; mask++)
        if (dp[k][mask]) {
            cout << "YES\n";
            while (k > 0) {
                bool first = true;
                int cur = pred[k][mask].group;
                assert(cur > 0);
                for (int i=0; i<n; i++)
                    if (cur & (1 << i)) {
                        if (first) first = false;
                        else cout << '+';
                        cout << table[atoms[i]];
                    }
                cout << "->" << table[goal[k-1]] << "\n";
                mask = pred[k][mask].taken;
                k--;
            }
            return 0;
        }

    cout << "NO\n";

    return 0;
}