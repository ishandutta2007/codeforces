#include <iostream>
#include <string>
using namespace std;
int N;
string s;
int ans;
bool vis[26];
int cur;
int test(int l, int r)
{
    int total = 0;
    for(int i=0; i<26; i++)
    {
        vis[i] = false;
    }
    for(int i=l; i<=r; i++)
    {
        cur = s[i] - 'a';
        if(cur >= 26 || cur < 0)
        {
            return 0;
        }
        vis[cur] = true;
    }
    for(int i=0; i<26; i++)
    {
        if(vis[i])
        {
            total++;
        }
    }
    return total;
}
int main()
{
    cin>>N>>s;
    for(int i=0; i<N; i++)
    {
        for(int j=i; j<N; j++)
        {
            ans = max(ans, test(i, j));
        }
    }
    cout<<ans<<endl;
}