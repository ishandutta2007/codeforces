#include <iostream>
#include <cstdio>
#include <iomanip>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
const int MAXN = 500100;

int N;
int arr[MAXN];
bool spec[MAXN];

vector <int> slist;
ll ans;

vector <int> ind;
int nval[MAXN], pval[MAXN];

inline bool cmp (int left, int right)
{
    return arr[left] < arr[right];
}

void solve (int start, int end) // closed open
{
    //cout << start << " " << end << "\n";
    if (start == end) return;
    
    ind.clear();
    for (int i = start; i < end; i++)
        ind.push_back (i);
    
    for (int i = start; i <= end; i++)
    {
        nval[i-1] = i;
        pval[i] = i - 1;
    }
    
    sort (ind.begin(), ind.end(), cmp);
    
    for (int i = 0; i < ind.size(); i++)
    {
        int cloc = ind[i];
        
        //cout << cloc << " " << pval[cloc] << " " << nval[cloc] << "\n";
        
        ans += min (arr[pval[cloc]], arr[nval[cloc]]);
        nval[pval[cloc]] = nval[cloc];
        pval[nval[cloc]] = pval[cloc];
    }
}

int main()
{
    ans = 0;
    
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        spec[i] = false;
    }
    
    if (N <= 2)
    {
        cout << "0\n";
        return 0;
    }
    
    int cmax = -1;
    for (int i = 0; i < N; i++)
        if (arr[i] > cmax)
        {
            cmax = arr[i];
            spec[i] = true;
        }
    cmax = -1;
    for (int i = N - 1; i >= 0; i--)
        if (arr[i] > cmax)
        {
            cmax = arr[i];
            spec[i] = true;
        }
    
    int lval = -1;
    for (int i = 0; i < N; i++)
    {
        if (spec[i])
        {
            if (lval != -1)
                solve (lval + 1, i);
            lval = i;
            
            slist.push_back (arr[i]);
        }
    }
    
    sort (slist.begin(), slist.end());
    for (int i = 0; i < slist.size() - 2; i++)
        ans += slist[i];
    
    cout << ans << "\n";
    //system ("Pause");
    return 0;
}