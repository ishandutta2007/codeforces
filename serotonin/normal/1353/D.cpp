#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

int a[sz];

typedef pair <int, int> pii;
#define x first
#define y second

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        priority_queue <pii> pq;
        pq.push({n, -1});

        for(int i=1; i<=n; i++) {
            pii p = pq.top();
            pq.pop();

            int pos = 0 - p.y, len = p.x;
            int z = pos + (len - 1) / 2;
            a[z] = i;

            pq.push({pos + len - z - 1, - z - 1});
            pq.push({z - pos, - pos});
        }

        for(int i=1; i<=n; i++) printf("%d ", a[i]);
        puts("");
    }
}