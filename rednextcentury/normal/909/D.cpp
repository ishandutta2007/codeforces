#include<bits/stdc++.h>
using namespace std;
vector<pair<int,char> > Move(vector<pair<int,char> > v)
{
    vector<pair<int,char> > cur;
    for (int i=0;i<v.size();i++)
    {
        if (i==0)
            v[i].first--;
        else if (i+1==v.size())
            v[i].first--;
        else v[i].first-=2;
        if (v[i].first<=0)continue;
        if (cur.size() && cur[cur.size()-1].second == v[i].second)
            cur[cur.size()-1].first+=v[i].first;
        else
            cur.push_back(v[i]);
    }
    return cur;
}
vector<pair<int,char> > ret;
int main()
{
    string s;
    cin>>s;
    int cur = 1;
    char x = s[0];
    for(int i=1;i<s.size();i++)
    {
        if (s[i]==s[i-1])cur++;
        else
        {
            ret.push_back(make_pair(cur,x));
            cur=1,x=s[i];
        }
    }
    ret.push_back(make_pair(cur,x));
    int num=0;
    while(ret.size()>1){
        ret = Move(ret);
        num++;
    }
    cout<<num<<endl;
}