

    #include<bits/stdc++.h>
    #define rep(i,a,b) for (register int i=a;i<=b;++i)
    #define req(i,a,b) for (register int i=a;i>=b;--i)
    using namespace std;
    int T,n,a[5];
    string s[210];
    int main()
    {
        cin>>T;
        while(T--)
        {
            cin>>n;
            rep(i,1,n) cin>>s[i];
            a[0]=s[1][1]-'0',a[1]=s[2][0]-'0',a[2]=s[n-1][n-1]-'0',a[3]=s[n][n-2]-'0';
            if (a[0]==a[1]&&a[2]==a[3]&&a[0]!=a[2]) puts("0");
            else if (a[0]==a[1]&&a[2]==a[3]&&a[0]==a[2]) printf("2\n1 2\n2 1\n");
            else if (a[0]!=a[1]&&a[2]==a[3]&&a[1]!=a[2]) printf("1\n1 2\n");
            else if (a[0]!=a[1]&&a[2]==a[3]&&a[0]!=a[2]) printf("1\n2 1\n");
            else if (a[2]!=a[3]&&a[0]==a[1]&&a[2]!=a[0]) printf("1\n%d %d\n",n,n-1);
            else if (a[2]!=a[3]&&a[0]==a[1]&&a[3]!=a[0]) printf("1\n%d %d\n",n-1,n);
            else if (a[0]==a[2]&&a[1]==a[3]) printf("2\n%d %d\n2 1\n",n-1,n);
            else if (a[0]==a[3]&&a[1]==a[2]) printf("2\n%d %d\n1 2\n",n-1,n);
        }
        return 0;
    }