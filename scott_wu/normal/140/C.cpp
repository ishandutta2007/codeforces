#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;
const int MAXN = 100100;

struct data
{
    int nballs, bsize;
};

inline bool operator < (data left, data right)
{
    return left.bsize < right.bsize;
}

int n;
int sballs[MAXN];
priority_queue <data> pq;
int res[MAXN][3];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> sballs[i];
    sort (sballs, sballs + n);
    data temp;
    int cur = 0;
    while (cur < n)
    {
        int lcur = cur;
        while (cur < n && sballs[cur] == sballs[lcur])
            cur++;
        temp.nballs = sballs[lcur];
        temp.bsize = cur - lcur;
        pq.push (temp);
    }
    int ans = 0;
    while (pq.size() >= 3)
    {
        data l1 = pq.top(); pq.pop();
        data l2 = pq.top(); pq.pop();
        data l3 = pq.top(); pq.pop();
        if (l3.bsize <= 0) break;
        res[ans][0] = l1.nballs;
        res[ans][1] = l2.nballs;
        res[ans][2] = l3.nballs;
        ans++;
        l1.bsize--; l2.bsize--; l3.bsize--;
        if (l1.bsize > 0) pq.push (l1);
        if (l2.bsize > 0) pq.push (l2);
        if (l3.bsize > 0) pq.push (l3);
    }
    cout << ans << "\n";
    for (int i = 0; i < ans; i++)
    {
        sort (res[i], res[i] + 3);
        cout << res[i][2] << " " << res[i][1] << " " << res[i][0] << "\n";
    }
    //system ("Pause");
    return 0;
}