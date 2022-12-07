#include <iostream>
#include <fstream>
#define MAXN 200200
using namespace std;
int T; string s, t; int g, ans;
int prev0[MAXN];
int main()
{
    cin>>T;
    for(int i=0; i<T; i++)
    {
        cin>>s;
        ans = 0;
        prev0[0] = 1;
        for(int j=0; j<s.length(); j++)
        {
            if(j != 0 && s[j] == '0')
            {
                prev0[j] = prev0[j-1];
            }
            else if(s[j] == '1')
            {
                prev0[j] = j+1;
            }
            else
            {
                prev0[j] = 0;
            }
        }
        for(int j=0; j<s.length(); j++)
        {
            if(s[j] == '0') continue;
            for(int k=1; k<min(19, (int)s.length()-j+1); k++)
            {
                t = s.substr(j, k); g = 0;
                for(int l=0; l<t.length(); l++)
                {
                    g += ((t[l]-'0')*(1<<(t.length()-1-l)));
                }
                if(j != 0 && prev0[j-1] <= j+k-g)
                {
                    ++ans;
                }
                else if(j == 0 && j+k-g >= 0)
                {
                    ++ans;
                }
            }
        }
        cout<<ans<<endl;
    }
}