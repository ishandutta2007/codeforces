#include<bits/stdc++.h>
#define int long long
#define rd(x) x=read()
using namespace std;
const signed N=1e3+5;
const int inf=0x3f3f3f3f;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}

int n,m,flag;
char ch[N][N];
int ans[N*N];
signed main()
{
	int T;cin>>T;
	while (T--)
	{
		flag=0;
		rd(n);rd(m);
		for (int i=1;i<=n;i++) scanf("%s",ch[i]+1);
		if (m%2==1)
		{
			puts("YES");
			for (int i=1;i<=m+1;i++) cout<<(i%2?1:2)<<" ";puts(""); 
			flag=1;
		}
		if (flag) continue;
		for (int i=1;i<=n;i++) for (int j=i+1;j<=n;j++)
		{
			if (flag) break;
			if (ch[i][j]==ch[j][i])
			{
				puts("YES");
				for (int k=1;k<=m+1;k++) cout<<(k%2?i:j)<<" ";puts(""); 
				flag=1;
			}
		}
		if (flag) continue;
		if (n==2) {puts("NO");continue;}
		if (m%4==2)
        {
            int x,y,z;
            if (ch[3][1]==ch[1][2]) x=3,y=1,z=2;
            if (ch[1][2]==ch[2][3]) x=1,y=2,z=3;
            if (ch[2][3]==ch[3][1]) x=2,y=3,z=1;
            puts("YES");
            for (int i=1;i<=m+1;i++)
            {
                if (i%4==1) cout<<x<<' ';
                if (i%2==0) cout<<y<<' ';
                if (i%4==3) cout<<z<<' ';
            }
            puts("");
            flag=1;
        }
        if (flag) continue;
        int x,y,z;
        if (ch[3][1]==ch[1][2]) x=3,y=1,z=2;
        if (ch[1][2]==ch[2][3]) x=1,y=2,z=3;
        if (ch[2][3]==ch[3][1]) x=2,y=3,z=1;
        puts("YES");
        for (int i=1;i<=m+1;i++)
        {
            if (i%4==2) cout<<x<<' ';
            if (i%2==1) cout<<y<<' ';
            if (i%4==0) cout<<z<<' ';
        }
        puts("");
	}
}