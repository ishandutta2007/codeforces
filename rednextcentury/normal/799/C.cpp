#include<bits/stdc++.h>
using namespace std;
int b[1000000];
int p[1000000];
char x[1000000];
int BD[1000000][2];
int BC[1000000][2];
int ID[1000000][2];
int IC[1000000][2];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,c,d;
    cin>>n>>c>>d;
    for (int i=1;i<=n;i++)
    {
        cin>>b[i]>>p[i]>>x[i];
        if (x[i]=='C')
        {
            if (b[i]>BC[p[i]][0])
                BC[p[i]][1]=BC[p[i]][0],IC[p[i]][1]=IC[p[i]][0],BC[p[i]][0]=b[i],IC[p[i]][0]=i;
            else if (b[i]>BC[p[i]][1])
                BC[p[i]][1]=b[i],IC[p[i]][1]=i;
        }
        else
        {
            if (b[i]>BD[p[i]][0])
                BD[p[i]][1]=BD[p[i]][0],ID[p[i]][1]=ID[p[i]][0],BD[p[i]][0]=b[i],ID[p[i]][0]=i;
            else if (b[i]>BD[p[i]][1])
                BD[p[i]][1]=b[i],ID[p[i]][1]=i;
        }
    }
    int BC0=BC[0][0],IC0=IC[0][0],BC1=BC[0][1],IC1=IC[0][1],BD0=BD[0][0],ID0=ID[0][0],BD1=BD[0][1],ID1=BD[0][1];
    for (int i=1;i<=100000;i++)
    {
        if (BC0>BC[i][0])
        {
            BC[i][1]=BC[i][0];
            IC[i][1]=IC[i][0];
            BC[i][0]=BC0;
            IC[i][0]=IC0;
        }
        else if (BC0>BC[i][1])
            BC[i][1]=BC0,IC[i][1]=IC0;
        if (BC1>BC[i][1])
            BC[i][1]=BC1,IC[i][1]=IC1;
        BC0=BC[i][0],IC0=IC[i][0];
        BC1=BC[i][1],IC1=IC[i][1];
        if (BD0>BD[i][0])
        {
            BD[i][1]=BD[i][0];
            ID[i][1]=ID[i][0];
            BD[i][0]=BD0;
            ID[i][0]=ID0;
        }
        else if (BD0>BD[i][1])
            BD[i][1]=BD0,ID[i][1]=ID0;
        if (BD1>BD[i][1])
            BD[i][1]=BD1,ID[i][1]=ID1;
        BD0=BD[i][0],ID0=ID[i][0];
        BD1=BD[i][1],ID1=ID[i][1];
    }
    int ans=0;
    for (int i=0;i<=d;i++)
    {
        int cur=BD[i][0]+BD[d-i][0];
        if (ID[i][0]==0 || ID[d-i][0]==0)
            continue;
        if (ID[i][0]==ID[d-i][0])
        {
            cur-=BD[d-i][0],cur+=BD[d-i][1];
            if (ID[d-i][1]==0)
                continue;
        }
        ans=max(ans,cur);
    }
    for (int i=0;i<=c;i++)
    {
        int cur=BC[i][0]+BC[c-i][0];
        if (IC[i][0]==0 || IC[c-i][0]==0)
            continue;
        if (IC[i][0]==IC[c-i][0])
        {
            cur-=BC[c-i][0],cur+=BC[c-i][1];
            if (IC[c-i][1]==0)
                continue;
        }
        ans=max(ans,cur);
    }
    if (IC[c][0]!=0 && ID[d][0]!=0)
        ans=max(ans,BC[c][0]+BD[d][0]);
    cout<<ans<<endl;
}