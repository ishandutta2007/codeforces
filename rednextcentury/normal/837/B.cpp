#include<bits/stdc++.h>
using namespace std;
char A[1000][1000];
int num1[1000],num2[1000];
char cur1[1000],cur2[1000];
char getColor(int a,int b,int c,int d)
{
    char mn=A[a][b];
    char mx=A[c][d];
    for (int i=a;i<=c;i++)
        for (int j=b;j<=d;j++)
            mn = min ( mn , A[i][j] ) , mx = max ( mx , A[i][j] );
    if (mn==mx)return mn;
    return '-';
}
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            cin>>A[i][j];
    // case 1
    bool c1=1;
    for (int i=0;i<n;i++)
    {
        char x=getColor(i,0,i,m-1);
        if (x=='-'){
            c1=0;break;
        }
        num1[x]++;
        cur1[i]=x;
    }
    if (n%3)
    {
        c1=0;
    }
    else
    {
        int N=n/3;
        for (int i=1;i<N;i++)
            if (cur1[i]!=cur1[i-1])
                c1=0;
        for (int i=N+1;i<2*N;i++)
            if (cur1[i]!=cur1[i-1])
                c1=0;
        for (int i=2*N+1;i<3*N;i++)
            if (cur1[i]!=cur1[i-1])
                c1=0;
        if (num1['R']!=num1['B'] || num1['R']!=num1['G'] || num1['G']!=num1['B'])
            c1=0;
    }
    // case 2
    bool c2=1;
    for (int i=0;i<m;i++)
    {
        char x=getColor(0,i,n-1,i);
        if (x=='-'){
            c2=0;break;
        }
        num2[x]++;
        cur2[i]=x;
    }
    if (m%3)
    {
        c2=0;
    }
    else
    {
        int N=m/3;
        for (int i=1;i<N;i++)
            if (cur2[i]!=cur2[i-1])
                c2=0;
        for (int i=N+1;i<2*N;i++)
            if (cur2[i]!=cur2[i-1])
                c2=0;
        for (int i=2*N+1;i<3*N;i++)
            if (cur2[i]!=cur2[i-1])
                c2=0;
        if (num2['R']!=num2['B'] || num2['R']!=num2['G'] || num2['G']!=num2['B'])
            c2=0;
    }
    if (c1 || c2)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}