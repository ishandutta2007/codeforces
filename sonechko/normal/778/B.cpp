#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 11;
int n,m;
map<string,int> mt;
int a[5001][1001];
string op1[N],op2[N];
int op[N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    {
        string s;
        cin>>s;
        mt[s]=i;
        cin>>s;
        cin>>s;
        if (s[0]=='0'||s[0]=='1')
        {
            for (int j=1; j<=s.size(); j++)
                if (s[j-1]=='0') a[i][j]=0; else a[i][j]=1;
            op[i]=0;
        } else
        {
            op1[i]=s;
            string ch;
            cin>>ch>>op2[i];
            if (ch=="XOR") op[i]=1; else
            if (ch=="AND") op[i]=2; else op[i]=3;
        }
    }
    string s="",t="";
    for (int j=m; j>=1; j--)
    {
        int ans1=0;
        for (int i=1; i<=n; i++)
        {
            if (op[i]!=0)
            {
                int k1=0;
                if (op1[i]!="?") k1=a[mt[op1[i]]][j];
                int k2=0;
                if (op2[i]!="?") k2=a[mt[op2[i]]][j];
                if (op[i]==1) {if ((k1^k2)==1) ans1++; a[i][j]=(k1^k2);}
                if (op[i]==2) {if ((k1&k2)==1) ans1++; a[i][j]=(k1&k2);}
                if (op[i]==3) {if ((k1|k2)==1) ans1++; a[i][j]=(k1|k2);}
            } else
            {
                if (a[i][j]==1) ans1++;
            }
        }
        int ans2=0;
        for (int i=1; i<=n; i++)
        {
            if (op[i]!=0)
            {
                int k1=1;
                if (op1[i]!="?") k1=a[mt[op1[i]]][j];
                int k2=1;
                if (op2[i]!="?") k2=a[mt[op2[i]]][j];
                if (op[i]==1) {if ((k1^k2)==1) ans2++; a[i][j]=(k1^k2);}
                if (op[i]==2) {if ((k1&k2)==1) ans2++; a[i][j]=(k1&k2);}
                if (op[i]==3) {if ((k1|k2)==1) ans2++; a[i][j]=(k1|k2);}
            } else
            {
                if (a[i][j]==1) ans2++;
            }
        }
        if (ans1<=ans2) s="0"+s; else s="1"+s;
        if (ans1>=ans2) t="0"+t; else t="1"+t;
    }
    cout<<s<<endl;
    cout<<t<<endl;
}