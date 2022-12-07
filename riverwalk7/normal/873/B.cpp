#include <iostream>
#include <fstream>
#include <vector>
#define MAXN 100100
using namespace std;
vector<int> s[2*MAXN];
int N;
char x;
int cur;
int ans;
int main()
{
    cin>>N;
    cur = MAXN;
    s[MAXN].push_back(0);
    for(int i=1; i<=N; i++)
    {
        cin>>x;
        if(x=='1')
        {
            cur++;
        }
        else
        {
            cur--;
        }
        s[cur].push_back(i);
    }
    for(int i=0; i<2*MAXN; i++)
    {
        if(s[i].size() >= 2)
        {
            ans = max(ans, s[i][s[i].size()-1]-s[i][0]);
        }
    }
    cout<<ans<<endl;
}