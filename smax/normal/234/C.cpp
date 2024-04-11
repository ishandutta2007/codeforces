#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t, zero = 0, neg[100000] = {0}, pos[100000] = {0};
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");
    fin >> n >> t;
    if (t < 0)
        neg[0] = 1;
    else if (t == 0)
        zero++;
    else
        pos[0] = 1;
    for (int i=1; i<n; i++) {
        fin >> t;
        if (t < 0) {
            neg[i] = neg[i-1] + 1;
            pos[i] = pos[i-1];
        } else if (t == 0) {
            zero++;
            neg[i] = neg[i-1];
            pos[i] = pos[i-1];
        } else {
            neg[i] = neg[i-1];
            pos[i] = pos[i-1] + 1;
        }
    }
    
    int mn = INT_MAX;
    for (int i=0; i<n-1; i++)
        mn = min(mn, pos[i] + neg[n-1] - neg[i]);
    
    fout << mn + zero << endl;
    
    return 0;
}