#include <bits/stdc++.h>
using namespace std;
int s[5009][29][29];
int f[919];
main()
{
    string S;
    cin >>S;
    for (int i=0; i<S.size(); i++)
        f[S[i]-'a']++;
    for (int i=1; i<S.size(); i++)
    {
        for (int j = 0; j < S.size(); j++)
        {
            s[i][S[j]-'a'][S[(i+j)%S.size()]-'a']++;
        }
    }
    double ANS=0;
    for (int i= 0; i < 26; i++)
    {
        if(f[i]==0) continue;
       int ans  = 0;
        for (int j = 1; j < S.size(); j++)
        {
            int X=0;
            for (int k = 0; k < 26; k++)
            {
                if(s[j][i][k] ==1) X++;
            }
            ans=max(ans,X);
        }
        //cout <<i<<" "<<ans<<endl;
        ANS+=1.0*ans/S.size();
    }
    printf("%.9f",ANS);
}