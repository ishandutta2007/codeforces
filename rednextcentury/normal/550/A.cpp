    #include <bits/stdc++.h>
    using namespace std;
    int main()
    {
        string s;
        cin>>s;
        int n=s.length();
        int mnA=n,mnB=n;
        int mxA=0,mxB=0;
        for (int i=0;i<n;i++)
        {
            if (i<n-1)
            {
                if (s[i]=='A' && s[i+1]=='B')
                    mnA=min(mnA,i),mxA=i;
                if (s[i]=='B' && s[i+1]=='A')
                    mnB=min(mnB,i),mxB=i;
            }
        }

        if (mnA==n || mnB==n)
            cout<<"NO"<<endl;
        else if (abs(mnA-mxB)<2 && abs(mnB-mxA)<2)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }