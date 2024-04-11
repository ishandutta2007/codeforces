#include <bits/stdc++.h>
using namespace std;
string A,B,C="()";
int a,b,c[]={1,-1},D[202][202][600];
int S(int i,int j,int k)
{
    if(k>200||k<0)
        return 1e9;
    if(!k&&i==a&&j==b)
        return 0;
    int &R=D[i][j][k];
    if(R+1)
        return R;
    R=1e9;
    for(int x=0;x<2;x++)
        R=min(R,1+S(i+(C[x]==A[i]),j+(C[x]==B[j]),k+c[x]));
    return R;
}
 
void P(int i,int j,int k)
{
    if(!k&&i==a&&j==b)
        return;
    int R=S(i,j,k);
    for(int x=0;x<2;x++)
        if(R==1+S(i+(C[x]==A[i]),j+(C[x]==B[j]),k+c[x]))
        {
            cout<<C[x];
            P(i+(C[x]==A[i]),j+(C[x]==B[j]),k+c[x]);
            return;
        }
}
 
int main()
{
    memset(D,-1,sizeof D);
    cin>>A>>B; a=A.size(); b=B.size(); A=A+'#'; B=B+'#';
    P(0,0,0);
}