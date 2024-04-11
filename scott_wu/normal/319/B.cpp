#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;
const int MAXN = 100100;

int N;
int num[MAXN];
bool use[MAXN];
int next[MAXN], prev[MAXN];

vector <int> plist, nlist;

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> num[i+1];
        use[i+1] = true;
        next[i+1] = i + 2, prev[i+1] = i;
    }
    
    for (int i = 1; i < N; i++)
        if (num[i] > num[i+1])
            plist.push_back (i+1);
    
    int count = 0;
    while (true)
    {
        bool found = false;
        for (int i = 0; i < plist.size(); i++)
        {
            int cval = plist[i];
            
            if (!use[cval]) continue;
            use[cval] = false;
            found = true;
            
            next[prev[cval]] = next[cval];
            prev[next[cval]] = prev[cval];
            
            if (prev[cval] >= 1 && next[cval] <= N && num[prev[cval]] > num[next[cval]])
                nlist.push_back (next[cval]);
        }
        
        if (!found) break;
        
        plist.clear();
        for (int i = 0; i < nlist.size(); i++)
            plist.push_back (nlist[i]);
        nlist.clear();
        
        count++;
    }
    
    cout << count << "\n";
    return 0;
}