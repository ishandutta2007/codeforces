#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 700 + 11;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    string ans="";
    ans+=s;
    k--;
    while (k>0)
    {
        int cc=0;
        for (int j=ans.size()-n+1; j<ans.size(); j++)
        {
            int c=1;
            for (int p=j; p<ans.size(); p++)
                if (ans[p]!=s[p-j]) c=0;
            if (c)
            {
                for (int p=ans.size()-j; p<s.size(); p++)
                    ans+=s[p];
                k--;
                cc=1;
                break;
            }
        }
        if (cc==0) {ans+=s; k--;}
    }
    cout<<ans<<endl;
}