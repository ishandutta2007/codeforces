#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>

using namespace std;
typedef long long ll;
const int MAXN = 101;

int N;
int rval[MAXN];
double cprob[MAXN];
priority_queue <pair <double, int> > pq;

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> rval[i];
    
    for (int i = 0; i < N; i++)
    {
        pq.push (make_pair (1e9, i));
        cprob[i] = 0;
    }
    
    double ans = 0, tot = 0;
    for (int i = 1; i <= 3e6; i++)
    {
        pair <double, int> ptop = pq.top();
        pq.pop();
        
        double rrate = ptop.first;
        int rloc = ptop.second;
        
        cprob[rloc] += rval[rloc] / 100. * (1 - cprob[rloc]);
        
        if (rrate > 1e8)
        {
            tot = 1.;
            for (int j = 0; j < N; j++)
                tot *= cprob[j];
            ans += tot * i;
        }
        else
        {
            ans += (rrate - 1) * tot * i;
            tot *= rrate;
        }
        
        double nadd = rval[rloc] / 100. * (1 - cprob[rloc]);
        pq.push (make_pair (nadd / cprob[rloc] + 1, rloc));
    }
    
    cout << fixed << setprecision(8);
    cout << ans << "\n";
    //system ("Pause");
    return 0;
}