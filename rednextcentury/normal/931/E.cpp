#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
vector<int> v[100];
string s;
int num[10005][30];
int main()
{
    cin>>s;
    int n=s.size();
    for (int i=0;i<s.size();i++)
        v[s[i]-'a'].push_back(i);
    long double ret=0;
    for (int i=0;i<26;i++)
    {
        for (int j=0;j<v[i].size();j++)
        {
            int id = v[i][j];
            for (int x=0;x<n;x++)
            {
                num[x][s[(id+x)%n]-'a']++;
            }
        }
        bool ok=0;
        long double cur=0;
        for (int j=0;j<n;j++)
        {
            long double P=0;
            for (int x=0;x<26;x++)
            {
                if (num[j][x]==1)
                    P+=(1.0/v[i].size());
                num[j][x]=0;
            }
            cur=max(cur,P);
        }
        long double L = v[i].size();
        L/=n;
        ret+=cur*L;
    }
    cout<<setprecision(10)<<fixed<<ret<<endl;
}