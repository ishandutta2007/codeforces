#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;
const int MAXN = 200100;
const int MAXC = 30;

int N, M;
string lstr, rstr;
int ps[MAXC][MAXN];
int lbest[MAXN];
int rbest[MAXN];

int main()
{
    for (int i = 0; i < MAXC; i++)
        ps[i][0] = 0;
    
    cin >> lstr >> rstr;
    N = lstr.length(), M = rstr.length();
    
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < MAXC; j++)
            ps[j][i+1] = ps[j][i];
        ps[(rstr[i] - 'a')][i+1]++;
    }
    
    lbest[0] = 0;
    for (int i = 0; i < N; i++)
    {
        lbest[i+1] = lbest[i];
        if (lbest[i] < M && lstr[i] == rstr[lbest[i]])
            lbest[i+1]++;
    }
    
    rbest[N] = M;
    for (int i = N - 1; i >= 0; i--)
    {
        rbest[i] = rbest[i+1];
        if (rbest[i] > 0 && lstr[i] == rstr[rbest[i]-1])
            rbest[i]--;
    }
    
    bool ans = true;
    for (int i = 0; i < N; i++)
    {
        int hi = min (lbest[i] + 1, M), lo = max (rbest[i+1] - 1, 0);
        if (!(ps[lstr[i] - 'a'][hi] - ps[lstr[i] - 'a'][lo] > 0))
        {
            ans = false;
            //cout << i << "\n";
        }
    }
    if (ans)
        cout << "Yes\n";
    else
        cout << "No\n";
    //system ("Pause");
    return 0;
}