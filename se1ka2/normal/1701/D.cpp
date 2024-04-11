#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> P;

vector<P> v[500005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i <= n; i++)
        {
            v[i].clear();
        }
        int b[500005];
        for (int i = 1; i <= n; i++)
        {
            cin >> b[i];
            if (b[i] == 0)
            {
                v[n].push_back(P(i + 1, i));
            }
            else
            {
                int left = 0, right = n + 1;
                while (right - left > 1)
                {
                    int mid = (right + left) / 2;
                    if (i / mid >= b[i])
                    {
                        left = mid;
                    }
                    else
                    {
                        right = mid;
                    }
                }
                int l = left;
                left = 0, right = n + 1;
                while (right - left > 1)
                {
                    int mid = (right + left) / 2;
                    if (i / mid <= b[i])
                    {
                        right = mid;
                    }
                    else
                    {
                        left = mid;
                    }
                }
                v[l].push_back(P(right, i));
            }
        }
        int ans[500005];
        priority_queue<P> que;
        for (int i = n; i > 0; i--)
        {
            for (P p : v[i])
            {
                que.push(p);
            }
            P p = que.top();
            que.pop();
            ans[p.second] = i;
        }
        for (int i = 1; i <= n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}