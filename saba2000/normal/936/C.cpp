#include<bits/stdc++.h>
#define psi  pair < string ,int>
#define fi first
#define se second
#define pb push_back
#define sz size
using namespace std;
int f[3492],g[2411];
string s,t;

    int n;
int fl(int k)
{
     string S="",P="";
        for (int i = 0; i< n-k; i++)
            P+=t[i];
        for (int j = n-k; j<n; j++)
            S+=t[j];
            reverse(S.begin(),S.end());
        t = S+P;
        S="",P="";
}
main()
{
    cin >>n;
    cin >> s >> t;
    swap(s,t);
    for (int i = 0; i < n; i++)
    {
        f[s[i]]++;
        g[t[i]]++;
    }
    for (int i ='a'; i<='z'; i++)
    {
        if(f[i]!=g[i])
        {
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<3*n<<endl;
    for (int i= n-1 ;i >=0 ; i--)
    {
        int k = 0;
        for (int j = n-1; j>=0; j--)
        {
            if(t[j]==s[i]) {k = j; break;}
        }
        reverse(t.begin(),t.end());
        cout<<n<<" "<<k<<" "<<1<<" ";
        fl(k); fl(1);
    }
}
/*
ABxC
C'xB'A'
ABC'x
xABC'




Ax ...

*/