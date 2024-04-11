#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;
typedef long long ll;
const int MAXN = 100100;

int N;
int n, d;
ll x;
int a[MAXN], b[MAXN];

//x is 64-bit variable;
ll getNextX() {
    x = (x * 37 + 10007) % 1000000007;
    return x;
}
void initAB() {
    int i;
    for(i = 0; i < n; i = i + 1){
        a[i] = i + 1;
    }
    for(i = 0; i < n; i = i + 1){
        swap(a[i], a[getNextX() % (i + 1)]);
    }
    for(i = 0; i < n; i = i + 1){
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    }
    for(i = 0; i < n; i = i + 1){
        swap(b[i], b[getNextX() % (i + 1)]);
    }
}

int prev[MAXN], next[MAXN];
vector <int> pposs;
int ans[MAXN];
int loc[MAXN];

int main()
{
    cin >> n >> d >> x;
    N = n;
    
    initAB();
    
    for (int i = 0; i < N; i++)
        loc[a[i]] = i;
    
    for (int i = 0; i <= N + 1; i++)
    {
        next[i] = i + 1;
        prev[i+1] = i;
    }
    
    for (int i = 0; i < N; i++)
        if (b[i])
            pposs.push_back (i);
    
    for (int i = N - 1; i >= 0; i--)
    {
        if (!pposs.size())
        {
            ans[i] = 0;
            continue;
        }
        
        if (pposs.size() * (ll) pposs.size() >= i)
        {
            int cloc = N + 1;
            ans[i] = 0;
            while (cloc > 0)
            {
                cloc = prev[cloc];
                if (b[i - loc[cloc]])
                {
                    ans[i] = cloc;
                    break;
                }
            }
        }
        else
        {
            ans[i] = 0;
            for (int j = 0; j < pposs.size(); j++)
            {
                ans[i] = max (ans[i], a[i - pposs[j]]);
            }
        }
        
        if (b[i])
            pposs.pop_back();
        next[prev[a[i]]] = next[a[i]];
        prev[next[a[i]]] = prev[a[i]];
    }
    
    for (int i = 0; i < N; i++)
        cout << ans[i] << "\n";
    //system ("Pause");
    return 0;
}