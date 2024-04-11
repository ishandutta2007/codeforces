#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int dp[32][32];

int main()
    {
    int n;
    cin >> n;
    string s;
    for(int i=0; i<n; i++)
        {
        cin >> s;
        int m=s.size();




        for(int j=0; j<26; j++)
            {
            if(dp[j][s[0]-'a']) dp[j][s[m-1]-'a']=max(dp[j][s[m-1]-'a'], dp[j][s[0]-'a']+m);
            }


        dp[s[0]-'a'][s[m-1]-'a']=max(dp[s[0]-'a'][s[m-1]-'a'], m);
        }


    int res=0;
    for(int i=0; i<26; i++)
        {
        res=max(res,dp[i][i]);
        }

    cout << res << endl;

    return 0;
    }