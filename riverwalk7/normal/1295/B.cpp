#include <iostream>
#include <fstream>
#define MAXN 100100
using namespace std;
int T, n, x, tot, ans; string s;
int p[MAXN];
int main()
{
    cin>>T;
    for(int i=0; i<T; i++)
    {
        cin>>n>>x>>s;
        tot = 0; ans = 0;
        for(int j=0; j<n; j++)
        {
            if(s[j] == '0')
            {
                p[j+1] = p[j] + 1;
                tot += 1;
            }
            else
            {
                p[j+1] = p[j] - 1;
                tot -=1;
            }
        }
        for(int j=0; j<n; j++)
        {
            if(tot == 0 && p[j] == x)
            {
                ans = -1; break;
            }
            else if(tot != 0 && (x-p[j])%tot == 0 && (x-p[j])/tot >= 0)
            {
                ++ans;
            }
        }
        cout<<ans<<endl;
    }
}