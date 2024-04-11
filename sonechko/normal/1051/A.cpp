#include<bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    cin>>q;
    while (q--)
    {
        string s;
        cin>>s;
        s="."+s;
        int kol=3;
        int n=s.size()-1;
        for (int len=0; len<=3; len++)
        {
            int c=0;
            for (int l=1; l<=n-len+1; l++)
            {
                int r=l+len-1;
                int p1=0,p2=0,p3=0;
                for (int j=1; j<l; j++)
                    if (s[j]>='a'&&s[j]<='z') p1=1; else
                    if (s[j]>='A'&&s[j]<='Z') p2=1; else p3=1;
                for (int j=r+1; j<=n; j++)
                    if (s[j]>='a'&&s[j]<='z') p1=1; else
                    if (s[j]>='A'&&s[j]<='Z') p2=1; else p3=1;
                if (3-p1-p2-p3<=len)
                {
                    c=1;
                    for (int j=l; j<=r; j++)
                        if (p1==0) {s[j]='a'; p1=1;} else
                        if (p2==0) {s[j]='A'; p2=1;} else
                        if (p3==0) {s[j]='0'; p3=1;}
                    break;
                }
            }
            if (c==1) break;
        }
        cout<<"   ";
        for (int j=1; j<=n; j++)
            cout<<s[j];
        cout<<"\n";
    }
}
/**
aaa
brA
ft5
aTy
yPR
yM1
t5q
u7O
l98
Caa
RrA
Wt5
QTy
NPR
QM1
L5q
C7O
Z98
1aa
2rA
3t5
4Ty
5PR
6M1
75q
87O
998
AAb2b1
AbabBAb
541ju5613
54HJFGVJ342
**/