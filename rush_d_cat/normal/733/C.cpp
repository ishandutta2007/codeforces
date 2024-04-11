#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
#include <set>
#include <cmath>
#include <queue>
#include <map>
#include <utility>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int NICO = 605;
const int MAKI = 605;
const int INF = 10000007;
int a[NICO], b[MAKI];
int op[NICO];
char s[NICO];
int cnt = 0;
int ok = 1;
void solve(int l, int r)
{
    int max_ = 0;
    int ac = 0;
    for(int i = l; i <= r; i++)
    {
        max_ = max(max_, a[i]);
    }
    for(int i = l; i <= r; i++)
    {
        if(a[i] == max_)
        {
            if( !( (a[min(i+1,r)]==a[i]) && (a[max(i-1,l)]==a[i]) ) )
            {
                ac = 1;
                if(a[i] > a[min(i+1,r)])
                {
                    for(int j=i+1;j<=r;j++)
                    {
                        op[++cnt] = i;
                        s[cnt] = 'R';
                    }
                    int t = i;
                    for(int j=i-1;j>=l;j--)
                    {
                        op[++cnt] = t--;
                        s[cnt] = 'L';
                    }
                } else {
                    int t = i;
                    for(int j=i-1;j>=l;j--)
                    {
                        op[++cnt] = t--;
                        s[cnt] = 'L';
                    }
                    for(int j=i+1;j<=r;j++)
                    {
                        op[++cnt] = l;
                        s[cnt] = 'R';
                    }
                }
                
                break;
            }
        }
    }
    if(r==l) ac = 1;
    if(ac == 0) ok = 0;
}
int main()
{
    int n, k;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    cin >> k;
    for(int i=1;i<=k;i++)
    {
        cin >> b[i];
    }
    int sum = 0;
    int pos = k;
    int l = n+1, r = n+1;
    for(int i=n;i>=1;i--)
    {
        sum += a[i];
        if(sum == b[pos])
        {
            pos--;
            r = l-1;
            l = i;
            solve(l, r);
            sum = 0;
        }
    }
    if (pos != 0) ok = 0;
    if (sum != 0) ok = 0;
    if(!ok)
    {
        cout << "NO" << endl;
    }
    if(ok)
    {
        cout << "YES" << endl;
        for(int i = 1; i <= cnt; i++)
        {
            cout << op[i] << " " << s[i] << endl;
        }
    }
        
}