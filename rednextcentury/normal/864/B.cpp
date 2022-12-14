#include<bits/stdc++.h>
using namespace std;
set<int> s;
int mp[1000000];
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int best=0;
    for (int i=0;i<s.size();i++)
    {
        int num[30]={0};
        int cur=0;
        int j=i;
        while(1)
        {
            if (j==s.size())break;
            if (tolower(s[j])!=s[j])break;
            if (++num[s[j]-'a']==1)cur++;
            j++;
        }
        best=max(best,cur);
    }
    cout<<best<<endl;
}