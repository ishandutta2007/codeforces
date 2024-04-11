#include <bits/stdc++.h>
using namespace std;

#define MAXN 200000
#define LOG2N 20

int n, w[MAXN], h[MAXN], spt[MAXN][LOG2N];

// O(n log n) preprocessing
void preprocess() {
    for (int i=0; i<n; i++)
        spt[i][0] = i;  // RMQ of subarray starting at index i with length 1

    for (int j=1; (1<<j)<=n; j++)   // O(log n)
        for (int i=0; i+(1<<j)-1<n; i++) {  // O(n)
            if (h[spt[i][j-1]] > h[spt[i+(1<<(j-1))][j-1]])
                spt[i][j] = spt[i][j-1];    // start at index i of length 2^(j-1)
            else
                spt[i][j] = spt[i+(1<<(j-1))][j-1]; // start at index i + 2^(j-1) of length 2^(j-1)
        }
}

// O(1) query
int query(int i, int j) {
    if (i > j)
        return 0;
    int k = log2(j - i + 1);
    if (h[spt[i][k]] >= h[spt[j-(1<<k)+1][k]])
        return h[spt[i][k]];
    else
        return h[spt[j-(1<<k)+1][k]];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int totalW = 0;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> w[i] >> h[i];
        totalW += w[i];
    }

    preprocess();
    for (int i=0; i<n; i++)
        cout << (totalW - w[i]) * max(query(0, i-1), query(i+1, n-1)) << " ";
    cout << "\n";

    return 0;
}