#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;
const int MAXN = 200100;

int N;
int arr[MAXN];
int diff[MAXN]; // diff for partial sum

inline void add (int lo, int hi) // add to contiguous range
{
    //cout << lo << " " << hi << "\n";
    diff[lo]++;
    diff[hi+1]--;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    
    for (int i = 0; i < MAXN; i++)
        diff[i] = 0;
    
    if (arr[1] < arr[0])
        add (1, N - 1);
    
    int root = 0;
    for (int i = 2; i < N; i++)
    {
        int cloc = i - 1;
        while (root * root < cloc)
            root++;
        
        for (int j = 1; j <= root; j++)
        {
            int x = cloc/j;
            if (arr[i] < arr[x])
                add (j, j);
        }
        
        int lo = root + 1;
        for (int j = root; j >= 1; j--)
        {
            int nloc = cloc / j;
            if (nloc >= lo)
            {
                if (arr[i] < arr[j])
                    add (lo, nloc);
                lo = nloc + 1;
            }
        }
        
        if (arr[i] < arr[0])
            add (lo, N - 1);
    }
    
    int res = 0;
    for (int i = 0; i < N; i++)
    {
        res += diff[i];
        if (i > 1) cout << " ";
        if (i) cout << res;
    }
    cout << "\n";
    
    return 0;
}