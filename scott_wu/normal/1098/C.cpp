#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXN = 100100;

int N, res;
ll S;

ll vv[MAXN];

bool works (int K)
{
    vv[0] = 0;
    for (int i = 1; i <= N; i++)
    {
        int n1 = (i - 1) / K;
        int n2 = n1 + 1;
        int c2 = (i - 1) % K;
        int c1 = K - c2;
        vv[i] = i + (c1 * vv[n1]) + (c2 * vv[n2]);
    }
    //cout << K << " " << vv[N] << "\n";
    return (vv[N] <= S);
}

vector <int> ans;

void figure (int cloc, int ng, ll stot)
{
    //cout << cloc << " " << ng << " " << stot << endl;
    if (ng == 1) return;
    if (stot == vv[ng])
    {
        for (int i = 0; i < res; i++)
        {
            int n1 = (ng - 1) / res;
            if (i < ((ng - 1) % res))
                n1++;
            if (n1)
            {
                ans.push_back(cloc);
                figure (ans.size(), n1, vv[n1]);
            }
            else break;
        }
        return;
    }

    int ct = ng - 1;
    while (true)
    {
        int nleft = ng - 1 - ct;
        int n1 = nleft / (res - 1);
        int n2 = n1 + 1;
        int c2 = nleft % (res - 1);
        int c1 = (res - 1) - c2;
        ll dtot = ng + vv[ct] + c1 * vv[n1] + c2 * vv[n2];
        //cout << "at " << cloc << " " << ct << " " << dtot << " " << stot << "\n";
        if (dtot <= stot)
        {
            for (int i = 0; i < c1; i++)
                if (n1)
                {
                    ans.push_back(cloc);
                    figure (ans.size(), n1, vv[n1]);
                }
            for (int i = 0; i < c2; i++)
            {
                ans.push_back(cloc);
                figure (ans.size(), n2, vv[n2]);
            }
            ans.push_back(cloc);
            figure (ans.size(), ct, vv[ct] + (stot - dtot));
            return;
        }
        ct--;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> N >> S;
    if (N * (ll) (N + 1) / 2 < S)
    {
        cout << "No\n";
        return 0;
    }
    if (2 * N - 1 > S)
    {
        cout << "No\n";
        return 0;
    }

    int lo = 1, hi = N - 1;
    while (lo < hi)
    {
        int mid = (lo + hi) / 2;
        if (works (mid))
        {
            hi = mid;
        }
        else
        {
            lo = mid + 1;
        }
    }

    //cout << lo << "\n";
    res = lo;

    vv[0] = 0;
    for (int i = 1; i <= N; i++)
    {
        int n1 = (i - 1) / res;
        int n2 = n1 + 1;
        int c2 = (i - 1) % res;
        int c1 = res - c2;
        vv[i] = i + (c1 * vv[n1]) + (c2 * vv[n2]);
    }

    figure (0, N, S);

    cout << "Yes\n";
    for (int i = 0; i < ans.size(); i++)
    {
        if (i) cout << " ";
        cout << ans[i] + 1;
    }
    cout << "\n";
}