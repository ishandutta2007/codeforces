#include <bits/stdc++.h>

using namespace std;
int pos[1100000];
int neg[1100000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int zero=0;
    for (int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        int ne=0,po=0;
        int sum=0;
        for (int j=0;j<s.size();j++)
        {
            if (s[j]==')')
            {
                if (sum==0)ne++;
                else sum--;
            }
            else
            {
                sum++;
            }
        }
        if (sum>0 && ne>0)continue;
        if (sum>0)pos[sum]++;
        else if (ne>0)neg[ne]++;
        else zero++;
    }
    int ret=0;
    for (int i=1;i<=1000000;i++)
        ret+=min(pos[i],neg[i]);
    ret+=zero/2;
    cout<<ret<<endl;
}