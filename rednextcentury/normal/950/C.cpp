#include <bits/stdc++.h>
using namespace std;
#define ll long long
set<int> Z;
set<int> O;
string s;
vector<int> ret[1000000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin>>s;
    for (int i=0;i<s.size();i++)
    {
        if (s[i]=='0')Z.insert(i);
        else O.insert(i);
    }
    int tot=0;
    while(Z.size())
    {
        int p = *Z.begin();
        Z.erase(Z.begin());
        int need = 1;
        ret[tot].push_back(p);
        while(1)
        {
            if (need==0)
            {
                set<int>::iterator it = Z.lower_bound(p);
                if (it==Z.end())
                    break;
                p=*it;
                ret[tot].push_back(p);
                need=1-need;
                Z.erase(it);
            }
            else
            {
                set<int>::iterator it = O.lower_bound(p);
                if (it==O.end())
                    break;
                p=*it;
                ret[tot].push_back(p);
                need=1-need;
                O.erase(it);
            }
        }
        tot++;
        if (need==0)
        {
            cout<<-1<<endl;
            return 0;
        }
    }
    if (O.size()>0)
    {
        cout<<-1<<endl;
        return 0;
    }
    cout<<tot<<endl;
    for (int i=0;i<tot;i++)
    {
        cout<<ret[i].size();
        for (int j=0;j<ret[i].size();j++)
            cout<<' '<<ret[i][j]+1;
        cout<<endl;
    }
}