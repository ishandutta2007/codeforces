 #include <bits/stdc++.h>
    using namespace std;
    int main()
    {
        string s;
        cin>>s;
        int n=s.length();
        for (int i=0;i<n;i++)
        {
            if (s[i]=='0' || s[i]=='8')
            {
                cout<<"YES"<<endl;
                cout<<s[i]<<endl;
                return 0;
            }
        }
        for (int i=0;i<n;i++)
        {
            for (int j=i+1;j<n;j++)
            {
                for (int k=j+1;k<n;k++)
                {
                    int x=((int)s[i]-'0' )* 100 + ((int)s[j]-'0' )* 10 + ((int)s[k]-'0' );
                    if (x%8==0)
                    {
                        cout<<"YES"<<endl;
                        cout<<s[i]<<s[j]<<s[k]<<endl;
                        return 0;
                    }
                }
            }
        }
         for (int i=0;i<n;i++)
        {
            for (int j=i+1;j<n;j++)
            {
                    int x=((int)s[i]-'0' )* 10 + ((int)s[j]-'0' );
                    if (x%8==0)
                    {
                        cout<<"YES"<<endl;
                        cout<<s[i]<<s[j]<<endl;
                        return 0;
                    }
            }
        }
        cout<<"NO"<<endl;
    }