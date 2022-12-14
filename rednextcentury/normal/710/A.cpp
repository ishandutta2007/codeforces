#include<bits/stdc++.h>
using namespace std;
int mv[][2]={{0,1},{1,0},{-1,0},{0,-1},{-1,-1},{-1,1},{1,1},{1,-1}};
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    char x;
    int y;
    cin>>x>>y;
    int a = x-'a';
    int b = y-1;
    int ret=0;
    for (int i=0;i<8;i++)
    {
        int A = a+mv[i][0];
        int B = b+mv[i][1];
        if (A>=0 && B>=0 && A<8 && B<8)ret++;
    }
    cout<<ret<<endl;
}