#include<bits/stdc++.h>
using namespace std;
main()
{
    string s;
    cin >> s;
    int ans=0;
    for(int i=0; i<s.size(); i++)
    {
        int ql=0,qr=0,r=0,l=0,N;

        for (int j=i; j<s.size(); j++)
        {
            if(s[j]=='(') r++;
            if(s[j]==')') l++;
            if(l+ql > r + qr && ql==0) break;
            if(l+ql > r + qr) {ql--; qr++;}
            if(s[j]=='?')
            {
                if(ql+l+1 > r+qr) qr++;
                else ql++;
            }

            if((j-i+1)%2!=0) continue;

            if(l+ql >=(j-i+1)/2 && l <=(j-i+1)/2 && r <=(j-i+1)/2) {ans++;
            }
        }
    }
    cout << ans << endl;
}