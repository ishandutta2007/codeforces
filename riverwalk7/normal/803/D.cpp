#include <iostream>
#include <string>
#include <vector>
#define MAXN 1000100
using namespace std;
string s;
int K;
int lbound, hbound, ans;
vector<int> x;
bool judge(int N)
{
    int cur = 0;
    int total = 0;
    for(int i=0; i<x.size(); i++)
    {
        if(x[i]-cur>N)
        {
            return false;
        }
        else if(i!=(x.size()-1)&&(x[i]-cur<=N&&x[i+1]-cur>N))
        {
            cur = x[i];
            total++;
        }
        else if(i==x.size()-1)
        {
            total++;
        }
    }
    if(total > K)
    {
        return false;
    }
    return true;
}
int main()
{
    cin>>K;
    cin.ignore();
    getline(cin, s);
    for(int i=0; i<s.length(); i++)
    {
        if(s[i]=='-'||s[i]==' ')
        {
            x.push_back(i+1);
        }
    }
    x.push_back(s.length());
    lbound = 0; hbound = MAXN;
    while(lbound != hbound)
    {
        ans = (lbound+hbound)/2;
        if(judge(ans))
        {
            hbound = ans;
        }
        else
        {
            lbound = ans + 1;
        }
    }
    while(!judge(ans))
    {
        ans++;
    }
    cout<<ans<<endl;
}