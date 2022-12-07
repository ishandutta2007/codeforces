#include <iostream>
#include <fstream>
#include <string>
#define MAXN 200200
#define MAXC 26
using namespace std;
int n[MAXN][MAXC];
int N, T;
string s, t;
int cur, ans;
int main()
{
    cin>>T;
    for(int i=0; i<T; i++)
    {
        cin>>s>>t; N = s.length(); ans = 0;
        for(int j=0; j<N; j++)
        {
            for(int k=0; k<MAXC; k++)
            {
                n[j][k] = -1;
            }
        }
        for(int j=0; j<N; j++)
        {
            for(int k=(j+N-1)%N; ; k = (k+N-1)%N)
            {
                n[k][s[j]-'a'] = j;
                if(s[k] == s[j])
                {
                    break;
                }
            }
        }
        cur = N-1;
        for(int j=0; j<t.length(); j++)
        {
            if(n[cur][t[j]-'a'] <= cur)
            {
                ++ans;
            }
            if(n[cur][t[j]-'a'] == -1)
            {
                ans = -1; break;
            }
            cur = n[cur][t[j]-'a'];
        }
        cout<<ans<<endl;
    }
}